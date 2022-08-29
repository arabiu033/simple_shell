#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * PSEUDO
 * The environment variable has the structure of a 2D array
 * Each row in this array stores strings in the for of Variable=VALUE
 * So the task here is to search for a Variable and return the VALUE
 * for that variable. So I will use strtok to cut the string separated
 * by the delimiter "="
 */

char *_getenv(char *name)
{
	int i, j, x, y;
	char *delim = "=", *buf, *holder, *holder_ptr, *token, *token_ptr;
	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			;
		holder = malloc(sizeof(char) * (j));
		if (holder == NULL)
			return (NULL);
		holder_ptr = strcpy(holder, environ[i]);
		buf = strtok(holder, delim);
		x = strcmp(buf, name);
		if (!x)
		{
			buf = strtok(NULL, delim);
			break;
		}
		free(holder);
	}

	token = malloc(sizeof(char) * strlen(buf));
	if (token == NULL)
		return (NULL);
	token_ptr = strcpy(token, buf);
	free(holder);

	return (token_ptr);
}

int main(void)
{
	char *buffer;

	/**
	 * buffer = _getenv("HOME");
	 * printf("_getenv: %s\n", buffer);
	 */

	buffer = _getenv("HOME");
	printf("_getenv: %s\n", buffer);

	free(buffer);
	return (0);
}
