#include "shell.h"

static char *holder = NULL;
/**
 * _strtok - string tokenizing
 * @str: pointer to the string to tokenize
 * @delim: the delimeter to use when tokenizing the string
 * Return: a string token
 */
char *_strtok(char *str, const char *delim)
{
	char *token, del;
	int strCount, delimCount, t;

	str = str ? str : holder;
	token = str;
	for (strCount = 0; str && str[strCount]; strCount++)
	{
		delimCount = t = 0;
		while (delim[delimCount] && !t)
		{
			del = delim[delimCount++];
			t = str[strCount] == del ? 1 : 0;
		}
		if (t)
		{
			holder = _strchr(str, del);
			holder = (holder + 1);
			str[strCount] = '\0';
			delimCount = 0;
			while (delim[delimCount])
			{
				if (delim[delimCount++] == *holder)
				{
					holder = holder + 1;
					delimCount = 0;
				}
			}
			break;
		}
	}
	if (!t)
		holder = NULL;

	return (token);
}
