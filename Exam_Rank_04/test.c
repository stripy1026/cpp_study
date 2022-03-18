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
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	exit_fatal(void)
{
	ft_putstr_fd("error fatal\n", 2);
	exit(1);
}

char	*ft_strdup(const char *s)
{
	int		i = -1;
	char	*p;

	if (!(p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		exit_fatal();
	while (s[++i])
		p[i] = s[i];
	p[i] = 0;
	return (p);
}

t_cmd	*create_cmd(t_cmd *tmp, char **args, int args_num, int is_pipe)
{
	t_cmd	*new;
	int		i = -1;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd))))
		exit_fatal();
	if (!(new->args = (char **)malloc(sizeof(char *) * (args_num + 1))))
		exit_fatal();
	while (++i < args_num)
		new->args[i] = ft_strdup(args[i]);
	new->args[i] = NULL;
	new->is_pipe = is_pipe;
	new->prev = tmp;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	return (new);
}

int		bt_cd(t_cmd *cmd);
int		non_bt(t_cmd *cmd, char **envp);
int		exec(t_cmd *cmd, char **envp)
{
	int	res = 0;
	while (cmd)
	{
		if (!strcmp(cmd->args[0], "cd"))
			res = bt_cd(cmd);
		else
			res = non_bt(cmd, envp);
		cmd = cmd->next;
	}
	return (res);
}

int		bt_cd(t_cmd *cmd)
{
	int	res = 0;
	int	i = 0;

	while (cmd->args[i])
		i++;
	if (i != 2)
	{
		ft_putstr_fd("error: cd: bad arguments\n", 2);
		return (1);
	}
	else if ((res = chdir(cmd->args[1])) < 0)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd("\n", 2);
	}
	return (res);
}

int		non_bt(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		res = 0;
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
		if ((res = execve(cmd->args[0], cmd->args, envp)) < 0)
		{
			ft_putstr_fd("error: cannot execute ", 2);
			ft_putstr_fd(cmd->args[0], 2);
			ft_putstr_fd("\n", 2);
		}
		exit(res);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
		if (cmd->is_pipe)
		{
			close(cmd->fd[1]);
			if (!cmd->next)
				close(cmd->fd[0]);
		}
		if (cmd->prev && cmd->prev->is_pipe)
			close(cmd->prev->fd[0]);
	}
	return (res);
}

void	clear(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i = 0;

	while (cmd)
	{
		i = 0;
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
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
	int		start = 1;
	int		last = 1;
	int		res = 0;
	int		is_pipe = 0;

	while (last < argc)
	{
		if (!strcmp(argv[last], "|") || !strcmp(argv[last], ";") || last + 1 == argc)
		{
			if (!strcmp(argv[last], "|"))
				is_pipe = 1;
			else if (!strcmp(argv[last], ";"))
				is_pipe = 0;
			else
			{
				is_pipe = 0;
				++last;
			}
			if (last - start != 0)
			{
				tmp = create_cmd(tmp, argv + start, last - start, is_pipe);
				if (!cmd)
					cmd = tmp;
			}
			start = last + 1;
		}
		last++;
	}
	res = exec(cmd, envp);
	clear(cmd);
	return (res);
}
