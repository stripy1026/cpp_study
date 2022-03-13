#include <stdio.h>
#include <stdlib.h>

typedef struct s_buffer
{
	char	*buf;
	int		cap;
	int		length;

	void	(*push_back)(struct s_buffer *, char);
	void	(*print_buffer)(struct s_buffer *);
}				t_buffer;

void	_push_back(t_buffer *buffer, char c);
void	_print_buffer(t_buffer *buffer);

void	init_buffer(t_buffer *buffer)
{
	buffer->buf = (char *)malloc(sizeof(char) * 1);
	buffer->buf[0] = 0;
	buffer->cap = 1;
	buffer->length = 0;
	buffer->push_back = _push_back;
	buffer->print_buffer = _print_buffer;
}

void	free_buffer(t_buffer *buffer)
{
	if (buffer->buf)
		free(buffer->buf);
}

void	_push_back(t_buffer *buffer, char c)
{
	char	*tmp;

	if (buffer->length >= buffer->cap - 1)
	{
		buffer->cap *= 2;
		tmp = (char *)malloc(sizeof(char) * buffer->cap);
		for (int i = 0; i < buffer->length; ++i)
			tmp[i] = buffer->buf[i];
		free(buffer->buf);
		buffer->buf = tmp;
	}
	buffer->buf[buffer->length++] = c;
	buffer->buf[buffer->length] = 0;
}

void	_print_buffer(t_buffer *buffer)
{
	printf("%s\n", buffer->buf);
}

int		main(void)
{
	t_buffer	buf;

	init_buffer(&buf);
	buf.push_back(&buf, 'H');
	buf.push_back(&buf, 'W');
	buf.print_buffer(&buf);
	free_buffer(&buf);
	return (0);
}
