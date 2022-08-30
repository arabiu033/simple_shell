#include "shell.h"

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
	char **args;
	size_t size = 0;
	char *command = NULL;
	int x = 1, i;
	ssize_t p = -1;
	pid_t fork_process;

	while (x)
	{
		command = NULL;
		if (p)
			printf("%dAmaterasu(<>) ",getppid());
		p = _getline(&command, &size, stdin);
		if (!p)
		{
			printf("\n");
			return(0);
		}
		for (i = 0; command[i] == ' '; i++)
			command = command + 1;
		args = _arguments(command);
		free(command);
		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		if (fork_process == 0)
		{
			printf("%d - child id", getpid());
			printf("%d - parenit id", getppid());
			if (execve(args[0], args, NULL) == -1)
				printf("%s: No such file or directory\n",
				       args[0]);
			exit(0);
		}
		else
		{
			wait(NULL);
			for (i = 0; i <= x; i++)
				free(args[i]);
			free(args);
		}
		++x;
	}
	return (0);
}
