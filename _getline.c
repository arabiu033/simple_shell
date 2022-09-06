#include "shell.h"

/**
 * _getline - for reading input from stram and files
 * @cmd_ptr: buffer to store the string captured
 * @fd: where to capture the string
 * Return: n - size of the string
 */
ssize_t _getline(int fd, char **cmd_ptr)
{
	char c;
	ssize_t n, len = 0, new_size, old_size;
	static char *commands;
	int x = 0;

	n = read(fd, &c, 1);
	if (!c)
		return (0);
	if (c != '\n')
	{
		commands = malloc(sizeof(char) * 5);
		if (!commands)
			return (0);

		old_size = new_size = 5;
		commands[len++] = c;
		while (n == 1)
		{
			if (len == old_size)
			{
				new_size = old_size + 5;
				commands = _realloc(commands, old_size * sizeof(char),
						    new_size * sizeof(char));
				old_size = new_size;
			}
			n = read(fd, &c, 1);
			if (n != 1 || c == '\n' || c == ';')
			{
				if (c == ';')
					x = 1;
				break;
			}
			else if (!c)
				return (0);
			commands[len++] = c;
		}
	}
	else
		return (1);
	old_size = new_size;
	new_size = len + 1;
	commands = _realloc(commands, old_size * sizeof(char),
			   new_size * sizeof(char));
	commands[len] = '\0';
	*cmd_ptr = commands;

	if (x)
		return (++len);
	return (len);
}
