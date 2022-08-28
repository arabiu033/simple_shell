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
	char **av;
	size_t size = 0;
	char *command = NULL;
	int x = 1, i;
	pid_t fork_process;

	while (x)
	{
		printf("Amaterasu(<>) ");
		_getline(&command, &size, stdin);
		for (i = 0; command[i]; i++)
		{
			if (command[i] == ' ' && command[i + 1] != ' ')
				x++;
		}
		av = _arguments(command, strlen(command), x);
		free(command);
		fork_process = fork();
		if (fork_process == -1)
			return (-1);
		if (fork_process == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(0);
		}
		else
		{
			wait(NULL);
			for (i = 0; i < x; i++)
				free(av[i]);
			free(av);
		}
	}
	return (0);
}
