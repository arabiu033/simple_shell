#include "shell.h"

ssize_t print_line(int fd, char **cmd_ptr)
{
	char c;
	ssize_t n, len = 0, new_size, old_size;
	static char *commands;

	n = read(fd, &c, 1);
	if (!c)
		return (0);
	if (c != '\n')
	{
		commands = malloc(sizeof(char) * 30);
		old_size = new_size = 1024;
		commands[len] = c;
		len++;
		while (n == 1)
		{
			if (len == old_size)
			{
				new_size = old_size + 1024;
				commands = _realloc(commands, old_size * sizeof(char),
						   new_size * sizeof(char));
				if (commands == NULL)
				old_size = new_size;
			}
			n = read(fd, &c, 1);
			if (!c)
				return (0);
			if (c == '\n')
				break;
			commands[len] = c;
			len++;
		}
	}
	else
		return (-1);
	old_size = new_size;
	new_size = len + 1;
	commands = _realloc(commands, old_size * sizeof(char),
			   new_size * sizeof(char));
	commands[len] = '\0';
	*cmd_ptr = commands;
	return (len);
}
