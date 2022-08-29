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
		*lineptr = malloc(sizeof(char) * 1);
<<<<<<< HEAD
=======

>>>>>>> 789cee18509e65c57388d8e9557a1cffdec06d46
		*n = 1;
	}

	do {
		c = getc(stream);

		if (c != EOF)
			((*lineptr)[count++]) = c;
		*lineptr = realloc(*lineptr, ++(*n));

	} while (c != EOF  && c != '\n');

	((*lineptr)[strlen(*lineptr) - 1]) = '\0';
	*n = (size_t) count;
	return (count);
}
