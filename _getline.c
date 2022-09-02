#include "shell.h"

/**
 * _getline - for reading input from stram and files
 * @lineptr: buffer to store the string captured
 * @n: size of the string captured
 * @stream: where to capture the string
 * Return: n - size of the string
 */
ssize_t _getline(char **lineptr, __attribute__((unused)) size_t *n, __attribute__((unused)) FILE *stream)
{
	static char *buffer;
	static char* val = NULL;
	ssize_t size;

	if (!val)
	{
		buffer = malloc(sizeof(char) * 1024);

		size = read(0, buffer, 1024);
		*lineptr = strtok(buffer, "\n");
		val  = strtok(NULL, "\n");
	}
	else
	{
		*lineptr = val;
		val  = strtok(NULL, "\n");

		if (!val)
			free(buffer);

	}

	return(size);
}
