#include "shell.h"

/**
 * _arguments - allocates memory for arguments
 * @str: the argument string
 * Return: pointer to argument string
 */
char **_arguments(char *str)
{
	char **arrayOfArgs, **dummyPtr = NULL, *holder;
	int numOfArgs = 2, count = 0, i = 0;

	arrayOfArgs = malloc(sizeof(char *) * numOfArgs);
	arrayOfArgs[1] = NULL;
	if (!arrayOfArgs)
		return (NULL);

	holder = _strtok(str, " ");
	while (holder)
	{
		arrayOfArgs[count] = malloc(sizeof(char) * strlen(holder));
		if (!arrayOfArgs[count])
		{
			free_pointer(arrayOfArgs, count);
			return (NULL);
		}

		for (i = 0; holder[i]; i++)
			arrayOfArgs[count][i] = holder[i];

		holder = _strtok(NULL, " ");

		if (holder)
			dummyPtr = (char **)
				_realloc(arrayOfArgs, numOfArgs,
					(++numOfArgs) * sizeof(*arrayOfArgs));

		if (holder && !dummyPtr)
		{
			free_pointer(arrayOfArgs, count);
			return (NULL);
		}
		if (dummyPtr)
			arrayOfArgs = dummyPtr;
		count++;

	}
	return (arrayOfArgs);
}

/**
 * free_pointer - free the malloc space
 * @ptr: pointer to free
 * @count: size of pointer
 * Return: void - nothing
 */
void free_pointer(char **ptr, int count)
{
	int i;

	if (!count)
	{
		free(ptr);
		return;
	}
	for (i = 0; i <= count; i++)
		free(ptr[i]);
	free(ptr);
}
