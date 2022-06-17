#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

typedef struct		s_cmd
{
	char			**args;
	int				is_pipe;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	prterr(const char *s)
{
	write(2, s, ft_strlen(s));
}

void	exit_fatal(void)
{
	prterr("error fatal\n");
	exit(1);
}


char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i = -1;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		exit_fatal();
	while (s[++i])
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

t_cmd	*create_cmd(t_cmd *tmp, char **args, int args_num, int is_pipe)
{
	t_cmd	*ret;
	int		i = -1;
	
	if (!(ret = (t_cmd *)malloc(sizeof(t_cmd))))
		exit_fatal();
	if (!(ret->args = (char **)malloc(sizeof(char *) * (args_num + 1))))
		exit_fatal();
	while (++i < args_num)
		ret->args[i] = ft_strdup(args[i]);
	ret->args[i] = NULL;
	ret->is_pipe = is_pipe;
	ret->next = NULL;
	ret->prev = tmp;
	if (tmp)
		tmp->next = ret;
	return (ret);
}

int		bt_cd(t_cmd *cmd)
{
	int	ret = 0;
	int	i = 0;

	while (cmd->args[i])
		++i;
	if (i != 2)
	{
		prterr("error: cd: bad arguments\n");
		return (1);
	}
	else if ((ret = chdir(cmd->args[1])) < 0)
	{
		prterr("error: cd: cannot change directory to ");
		prterr(cmd->args[1]);
		prterr("\n");
	}
	return (ret);
}

int		non_bt(t_cmd *cmd, char **envp)
{
	int		ret = 0;
	pid_t	pid;
	int		status;

	if (cmd->is_pipe)
		if (pipe(cmd->fd) < 0)
			exit_fatal();
	if ((pid = fork()) < 0)
		exit_fatal();
	if (!pid)
	{
		if (cmd->is_pipe && dup2(cmd->fd[1], 1) < 0)
			exit_fatal();
		if (cmd->prev && cmd->prev->is_pipe && dup2(cmd->prev->fd[0], 0) < 0)
			exit_fatal();
		if ((ret = execve(cmd->args[0], cmd->args, envp)) < 0)
		{
			prterr("error: cannot execute ");
			prterr(cmd->args[0]);
			prterr("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
		if (cmd->is_pipe)
		{
			close(cmd->fd[1]);
			if (!cmd->next)
				close(cmd->fd[0]);
		}
		if (cmd->prev && cmd->prev->is_pipe)
			close(cmd->prev->fd[0]);
	}
	return (ret);
}

int		exec(t_cmd *cmd, char **envp)
{
	int	ret = 0;
	
	while (cmd)
	{
		if (!strcmp(cmd->args[0], "cd"))
			ret = bt_cd(cmd);
		else
			ret = non_bt(cmd, envp);
		cmd = cmd->next;
	}
	return (ret);
}

void	clear(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		i = -1;
		while (cmd->args[++i])
			free(cmd->args[i]);
		free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_cmd	*tmp;
	t_cmd	*cmd;
	int		st = 1;
	int		en = 1;
	int		ret = 0;
	int		is_pipe = 0;

	while (en < argc)
	{
		if (!strcmp(argv[en], "|") || !strcmp(argv[en], ";") || en + 1 == argc)
		{
			if (!strcmp(argv[en], "|"))
				is_pipe = 1;
			else if (!strcmp(argv[en], ";"))
				is_pipe = 0;
			else
			{
				is_pipe = 0;
				en++;
			}
			if (en - st > 0)
			{
				tmp = create_cmd(tmp, argv + st, en - st, is_pipe);
				if (!cmd)
					cmd = tmp;
			}
			st = en + 1;
		}
		en++;
	}
	ret = exec(cmd, envp);
	clear(cmd);
	return (ret);
}
