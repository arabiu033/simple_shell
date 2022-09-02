#include "shell.h"

int print_line(int fd, char **cmd_ptr)
{
	char c;
	int n, len, new_size, old_size, i = 0;
	static char *commands;

	n = read(fd, &c, 1);
	if (c != '\n')
	{
		len = 1;
		commands = malloc(sizeof(char) * 1024);
		old_size = 1024;
		commands[i++] = c;
		while (n == 1)
		{
			if (len == 1024)
			{
				new_size = old_size + 1024;
				commands = _realloc(commands, old_size * sizeof(char),
						   new_size * sizeof(char));
				new_size = old_size;
			}
			n = read(1, &c, 1);
			if (c == '\n')
				break;
			else if (c == EOF)
				return (0);
			len++;
			commands[i++] = c;
		}
	}
	else if (c == EOF)
		return (0);
	else if (c == '\n')
		return (-1);
	new_size = len + 1;
	commands = _realloc(commands, len * sizeof(char),
			   new_size * sizeof(char));
	commands[len] = '\0';

	*cmd_ptr = commands;

	return (len);
}
