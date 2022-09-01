#include "shell.h"

/**
 * handle_sigint - signal handling for SIGINT
 * @signum: SIGINT
 */
void handle_sigint(__attribute__((unused)) int signum)
{
	;
}

/**
 * main - contains the main function of the program
 * @argc: Arguments passed into the CLI
 * @argv: Pointer to arguments string
 *
 * Description:  a super simple shell that can run commands
 * with their full path, without any argument.
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char **args, *command = NULL;
	size_t size = 0;
	int x = 1, i, atty = isatty(0), process_num = 0;
	ssize_t p = -1;
	pid_t fork_process;

	signal(SIGINT, handle_sigint);
	signal(SIGTSTP, SIG_IGN);
	while (x)
	{
		command = NULL;
		if (atty)
			_puts("(<>) ");
		p = _getline(&command, &size, stdin);
		if (p == -1)
			continue;
		if (!p)
		{
			if (atty)
				_puts("\n");
			return (0);
		}

		args = _arguments(command);
		free(command);
		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		if (fork_process == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				process_num++;
				error_message(getpid() - getppid(), argv[0], args[0]);
				kill(getpid(), SIGQUIT);
			}
		}
		wait(NULL);
		/* Create a separate function to free pointer */
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args[i]);
		free(args);
	}
	return (0);
}
