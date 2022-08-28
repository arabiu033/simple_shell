#include "shell.h"

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
