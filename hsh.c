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
	pid_t fork_process;

	while (x)
	{
		printf("Amaterasu(<>) ");
		_getline(&command, &size, stdin);
		for (i = 0; command[i] == ' '; i++)
			command = command + 1;
		args = _arguments(command);
		free(command);
		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		if (fork_process == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				printf("%s: No such file or directory\n",
				       args[0]);
			exit(0);
		}
		else
		{
			wait(NULL);
			for (i = 0; i < x; i++)
				free(args[i]);
			free(args);
		}
	}
	return (0);
}
