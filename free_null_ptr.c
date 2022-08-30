#include "shell.h"

/**
 * free_null_ptr - free the malloc space
 * @ptr: pointer to free
 */
void free_ptr(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free(ptr[i]);
	free(ptr[i]);
	free(ptr);
}
