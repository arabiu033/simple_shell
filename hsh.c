#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _arguments - allocates memory for arguments
 * @str: the argument string
 * @n: number of char in the string
 *
 * Return: pointer to argument string
 */
char **_arguments(char *str, int n)
{
	char **s;
	int i;

	s = malloc(2 * sizeof(char *));
	if (s == NULL)
		return (NULL);
	s[1] = NULL;
	s[0] = malloc((n + 1) * sizeof(char));
	if (s[0] == NULL)
	{
		for (i = 0; i < 2; i++)
			free(s[i]);
		free(s);
		return (NULL);
	}
	for (i = 0; i < n; i++)
		s[0][i] = str[i];
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
	int i = 0, n = 1, x;
	pid_t xxx;
	char command[50], ch;

	while (n)
	{
		for (i = 0; i < 50; i++)
			command[i] = '\0';
		printf("#cisfun$ ");
		ch = getchar();
		i = 0;
		while (ch != '\n' && ch != EOF)
		{
			command[i] = ch;
			i++;
			ch = getchar();
		}
		if (ch == EOF)
			break;
		av = _arguments(command, i);
		xxx = fork();
		if (xxx == -1)
			return (-1);
		if (xxx == 0)
		{
			if (execve(command, argv, NULL) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(0);
		}
		else
		{
			wait(NULL);
			for (x = 0; x < 2; x++)
				free(av[x]);
			free(av);
		}
	}
	return (0);
}
