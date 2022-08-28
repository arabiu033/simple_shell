#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * _arguments - allocates memory for arguments
 * @str: the argument string
 * @n: length of str (including NULL byte)
 * @x: Number of words in the command
 * Return: pointer to argument string
 */
char **_arguments(char *str, int n, int x)
{
	char **s;
	int i, len;

	s = malloc(x + 1 * sizeof(char *));
	if (s == NULL)
		return (NULL);
	s[x] = NULL;
	for (i = 0; i < x; i++)
	{
		/**
		 * This is where strtok() comes in. n now becomes
		 * the length of the tokens returned from strk()
		 */
		s[0] = malloc((n) * sizeof(char));
		if (s[0] == NULL)
		{
			for (i = 0; i <= x; i++)
				free(s[i]);
			free(s);
			return (NULL);
		}
	}
	len = n - 1;
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			/**
			  * This if statement might not be needed
			  * when integrating strtok() into the function
			  */
			s[0][i] = '\0';
			continue;
		}
		s[0][i] = str[i];
	}
	s[0][i] = '\0';

	return (s);
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
	char **av;
	size_t size = 1;
	char *command = NULL;
	int x = 1, i;
	pid_t fork_process;

	while (x)
	{
		printf("#cisfun$ ");
		getline(&command, &size, stdin);
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
