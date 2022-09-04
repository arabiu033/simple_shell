#include "shell.h"

/**
 * handle_sigint - signal handling for SIGINT
 * @signum: SIGINT
 */
void handle_sigint(__attribute__((unused)) int signum)
{
	_puts("\n($) ");
}

/**
 * main - contains the main function of the program
 * @argc: Arguments passed into the CLI
 * @argv: Pointer to arguments string
 *
 * Description: A simple shell
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char **args, *cmd, lol[15] = "Hello\n", *s = lol;
	int x = 1, process_num = 0, fd = 0;
	ssize_t p;
	pid_t fork_process;
	struct stat st;

	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, handle_sigint);

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			invalid_file(argv[0], argv[1]);
			return (127);
		}
	}
	while (x)
	{
		++x;
		if (isatty(fd))
			_puts("($) ");

		p = _getline(fd, &cmd);
		if (p == 1)
		{
			free(cmd);
			continue;
		}
		else if (!p)
		{
			if (isatty(fd))
				_putchar('\n');
			if (fd)
				close(fd);
			return (0);
		}
		args = _arguments(cmd);

		if (check_token(args) == 1)
		{
			free(cmd);
			free_array2D(args);
			continue;
		}
		else if (check_token(args) == 0)
		{
			free(cmd);
			free_array2D(args);
			free_which(NULL, 0);
			return (0);
		}
		else if (check_token(args) == -2)
		{
			free(cmd);
			free_array2D(args);
			continue;
		}

		s = _which(args[0]);
		if (!stat(s, &st))
			args[0] = s;
		else
		{
			error_message(x-1, argv[0], args[0]);
			continue;
		}

		free(cmd);

		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		else if (fork_process == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				process_num++;
				error_message(getpid() - getppid(), argv[0], args[0]);
				kill(getpid(), SIGQUIT);
			}
		}
		wait(NULL);
		free_array2D(args);
	}
	free_which(NULL, 0);
	return (0);
}
