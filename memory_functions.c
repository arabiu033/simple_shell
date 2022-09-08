#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: size of the previously allocated memory
 * @new_size: size of the newly allocated memory
 *
 * Return: a pointer to newly allocated memory
 */


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, max = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (i = 0; i < max; i++)
		p[i] = oldp[i];
	free(ptr);
	return (p);
}

/**
 * _malloc2D - Creates a malloc copy of a 2D array
 * @array_2D: The 2D array to copy and return
 *
 * Return: The malloc copy of array_2D
 */
char **_malloc2D(char **array_2D)
{
	int n, j = 0, x, y, len, size;
	char **holder;

	for (n = 0; array_2D[n]; n++)
		;
	size = n + 1;
	holder = malloc((size) * sizeof(char *));
	if (!holder)
		return (NULL);
	holder[n] = NULL;
	while (j < n)
	{
		len = _strlen(array_2D[j]);
		holder[j] = malloc((len +  1) * sizeof(char));
		if (holder[j] == NULL)
		{
			for (x = 0; x < j; x++)
				free(holder[x]);
			free(holder[n]);
			free(holder);
			return (NULL);
		}
		for (y = 0; y < len; y++)
			holder[j][y] = array_2D[j][y];
		array_2D[j][y] = '\0';
		j++;
	}

	return (holder);
}

/**
 * free_array2D - frees a 2D array
 * @array_2D: 2D array to free
 *
 * Return: void
 */
void free_array2D(char **array_2D)
{
	int i;

	for (i = 0; array_2D[i]; i++)
		free(array_2D[i]);
	free(array_2D[i]);
	free(array_2D);
}
