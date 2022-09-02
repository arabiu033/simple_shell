#include "shell.h"

/**
 * handle_sigint - signal handling for SIGINT
 * @signum: SIGINT
 */
void handle_sigint(__attribute__((unused)) int signum)
{
	printf("\n");
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
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char **args, *cmd;
	/* size_t size = 0; */
	int x = 1, atty = isatty(0), process_num = 0;
	ssize_t p = -1;
	pid_t fork_process;

	signal(SIGTSTP, SIG_IGN);
	while (x)
	{
		if (atty)
			_puts("($) ");

		p = print_line(0, &cmd);

		if (p == -1)
			continue;
		if (!p)
		{
			if (atty)
				_putchar('\n');
			return (0);
		}

		args = strtow(cmd);

		free(cmd);
		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		if (fork_process == 0)
		{
			if (execve(args[0], args, env) == -1)
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
