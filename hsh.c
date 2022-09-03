#include "shell.h"

/**
 * handle_sigint - signal handling for SIGINT
 * @signum: SIGINT
 */
void handle_sigint(int signum)
{
	(void) signum;
	_puts("\n");
}

/**
 * main - contains the main function of the program
 * @argc: Arguments passed into the CLI
 * @argv: Pointer to arguments string
 * @env: Contains the environment variable
 *
 * Description:  a super simple shell that can run commands
 * with their full path, without any argument.
 * Return: Always 0
 */
int main(int argc, char **argv, __attribute__((unused)) char **envp)
{
	char **args, *cmd;
	/* size_t size = 0; */
	int x = 1, process_num = 0, fd = 0;
	ssize_t p = -1;
	pid_t fork_process;

	signal(SIGTSTP, SIG_IGN);
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
		if (isatty(fd))
			_puts("($) ");
		p = print_line(fd, &cmd);
		if (p == -1)
			continue;
		else if (!p)
		{
			if (isatty(fd))
				_putchar('\n');
			if (fd)
				close(fd);
			return (0);
		}
		args = strtow(cmd);
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
	return (0);
}
