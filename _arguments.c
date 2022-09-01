#include "shell.h"

/**
 * _arguments - allocates memory for arguments
 * @str: the argument string
 * Return: pointer to argument string
 */
char **_arguments(char *str)
{
	char **arrayOfArgs, **dummyPtr = NULL, *holder;
	int numOfArgs = 1, count = 0, i = 0, newSize;

	arrayOfArgs = malloc(sizeof(char *) * numOfArgs);

	if (!arrayOfArgs)
		return (NULL);

	holder = _strtok(str, " ");
	while (holder)
	{
		arrayOfArgs[count] = malloc(sizeof(char) * (strlen(holder) + 1));
		if (!arrayOfArgs[count])
		{
			free_pointer(arrayOfArgs, count);
			return (NULL);
		}

		for (i = 0; holder[i]; i++)
			arrayOfArgs[count][i] = holder[i];
		arrayOfArgs[count][i] = '\0';

		holder = _strtok(NULL, " ");

		if (holder)
		{
			newSize = ++numOfArgs;
		        dummyPtr = (char **)
				realloc(arrayOfArgs,
					(newSize) * sizeof(char *));
		}

		if (holder && !dummyPtr)
		{
			free_pointer(arrayOfArgs, count);
			return (NULL);
		}
		if (dummyPtr)
			arrayOfArgs = dummyPtr;
		count++;

	}
	arrayOfArgs[count] = '\0';
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
