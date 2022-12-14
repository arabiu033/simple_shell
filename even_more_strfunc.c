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
	  {
	    free(holder);
		holder = NULL;
	  }

	return (token);
}

/**
 * _atoi - int
 * @s: pointer
 * Return: int.
 */
int _atoi(char *s)
{
	int i;
	int res = 0;
	int sig = -1;
	int brk = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sig = sig * -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10;
			res -= (s[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
			break;
	}
	res = sig * res;
	return (res);
}

/**
 * _tostr - converts a long unsigned int into a string
 * @n: long unsigned int
 *
 * Return: str
 */
char *_tostr(long unsigned int n)
{
	char str[22], *ptr;
	unsigned int holder = 1, dummy = n, x, i = 0;

	while (dummy > 9)
		{
			dummy = dummy / 10;
			holder = holder * 10;
		}

	while (holder != 0)
		{
			x = n / holder;
			n = n % holder;
			holder = holder / 10;
			str[i] = ('0' + x);
			i++;
		}
	str[i] = '\0';
	ptr = str;
	return (ptr);
}

/**
 * check_token - checks for string token
 * @str: pointer to strings to check
 *
 * Return: 1 if the token matches
 */
int check_token(char **str)
{

	if (!(_strcmp(str[0], "setenv")) && !(str[3]))
	{
		if(_setenv(str[1], str[2]) == -1)
			return (-2);
	}

	else if (!(_strcmp(str[0], "unsetenv")) && !str[2])
	{
		if (_unsetenv(str[1]) == -1)
			return (-2);
	}

	else if (!(_strcmp(str[0], "exit")))
		return (0);

	else if (!(_strcmp(str[0], "cd")))
	  {
		str[1] ? _cd(str[1]) : _cd(NULL);
		free_cd(NULL);
	  }

	else if (!(strcmp(str[0], "echo")) && str[1])
		return (2);

	else
		return (-1);

	return (1);
}
