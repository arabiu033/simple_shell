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
		if (*lineptr == NULL)
		{
			perror("In _getline.c: Unable to allocate memory with malloc");
		*n = 10;
		exit(98);
		}
	}

	do {
		c = getc(stream);

		if (c != EOF)
			((*lineptr)[count++]) = c;
		if (*n - count < 5)
		{
			*lineptr = _realloc(*lineptr, *n += 32);
			if (*lineptr == NULL)
			{
				perror("In _getline.c: Unable to reallocate memory with realloc\n");
				exit(99);
			}
		}

	} while (c != EOF  && c != '\n');

	((*lineptr)[strlen(*lineptr) - 1]) = '\0';
	*n = (size_t) count;
	return (count);
}
