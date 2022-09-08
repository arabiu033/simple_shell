#include "shell.h"

/**
 * echo_var - checks for echo expansion
 * @str: echo arguments
 *
 * Return: the expansion or the argument
 */
char *echo_var(char *str)
{
	char *ptr, *holder;
	int new_len, old_len, i;

	if (str[0] == '$' && str[1])
	{
		ptr = _strchr(str, str[1]);
		holder = _getenv(ptr);
		if (holder)
		{
			old_len = _strlen(str) + 1;
			new_len = _strlen(holder) + 1;
			str = _realloc(str, old_len * sizeof(char),
				       new_len * sizeof(char));
			if (str == NULL)
				return (NULL);
			for (i = 0; holder[i]; i++)
				str[i] = holder[i];
			str[i] = '\0';
			/* free(holder); */
			return (str);
		}
	}
	return (str);
}
