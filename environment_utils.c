#include "shell.h"

/**
 * _printenv - print the environment variables
 * Return: void - nothing
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i++]);
		_puts("\n");
	}
}

/**
 * _getenv - retrieve the value of get env
 * @name: the variable to retrieve
 * Reuturn: value of the environment varaible
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *str, *s = NULL;

	str = malloc(sizeof(char) * (_strlen((char *) name) + 1));
	str = _strcat(_strcpy(str, (char *) name), "=");
	while (environ[i])
	{
		s = strstr(environ[i], str);
		if (s)
		{
			_strtok(s, "=");
			s = _strtok(NULL, "=");
			return (s);
		}
		i++;
	}
	return (s);
}

/**
 * _path_directories - print the path directories
 * Return: void nothing
 */
void _path_directories(void)
{
	char *path, *dir;

	path = _getenv("PATH");
	dir = _strtok(path, ":");
	while (dir)
	{
		_puts(dir);
		_puts("\n");
		dir = _strtok(NULL, ":");
	}
}

/**
 * _path_directories_list - build the linkedlist of path directories
 * Return: lp - linked list of the path directoies
 */
lp *_path_directories_list(void)
{
	lp *head = NULL;
	char *path, *dir;

	path = _getenv("PATH");
	dir = _strtok(path, ":");
	while (dir)
	{
		linked_list(&head, dir);
		dir = _strtok(NULL, ":");
	}

	return (head);
}

/**
 * _setenv - adds variable to the environment
 * @name: variable name
 * @value: variable value
 * @overwrite: Overwrite condition if name already exist
 *
 * Description: Overwrites the variable if overwrit is non-zero
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i, j, x, old_len, new_len, len, a;
	char **environ_cpy;

	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], name))
		{
			if (overwrite)
			{
				environ_cpy = _malloc2D(environ);
				j = _strlen(name) + 1;
				new_len = j + _strlen(value);
				old_len = _strlen(environ_cpy[i]) + 1;
				environ_cpy[i] = _realloc(environ_cpy[i], old_len * sizeof(char),
					 (new_len + 1) * sizeof(char));
				for (x = 0; value[x]; x++)
				{
					environ_cpy[i][j] = value[x];
					j++;
				}
				environ_cpy[i][j] = '\0';
				environ = environ_cpy;
			}
			return (0);
		}
	}
	environ_cpy = _malloc2D(environ);
	for (old_len = 1; environ[old_len]; old_len++)
		;
	new_len = old_len + 1;
	environ_cpy = _realloc(environ_cpy, old_len * sizeof(char *), (new_len) * sizeof(char *));
	if (environ_cpy == NULL)
		return (-1);
	environ_cpy[old_len] = NULL;
	len = _strlen(name) + _strlen(value) + 2;
	environ_cpy[old_len - 1] = malloc(len * sizeof(char));
	if (environ_cpy[old_len - 1] == NULL)
		return (-1);
	for (a = 0; name[a]; a++)
		environ_cpy[old_len - 1][a] = name[a];
	environ_cpy[old_len - 1][a] = '=';
	a++;
	for (i = 0; value[i]; i++, a++)
		environ_cpy[old_len - 1][a] = value[i];
	environ_cpy[old_len - 1][a] = '\0';
	environ = environ_cpy;

	return (0);
}
