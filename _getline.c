#include "shell.h"

/**
 * _getline - for reading input from stram and files
 * @lineptr: buffer to store the string captured
 * @n: size of the string captured
 * @stream: where to capture the string
 * Return: n - size of the string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t count = 0;
	char c;

	if (!(*lineptr) || !(*n))
	{
		*lineptr = malloc(sizeof(char) * 10);
		*n = 10;
		((*lineptr)[0]) = '0';
	}

	do {
		c = getc(stream);

		if (!count && c == ' ')
			continue;
		else if (!count && c == '\n')
			return (-1);
		else if (c != EOF)
			((*lineptr)[count++]) = c;

		if (*n - count < 5)
			*lineptr = realloc(*lineptr, *n += 32);

	} while (c != EOF  && c != '\n');

	if (((*lineptr)[strlen(*lineptr) - 1]) == '\n')
		((*lineptr)[strlen(*lineptr) - 1]) = '\0';
	*n = (size_t) count;
	return (count);
}
