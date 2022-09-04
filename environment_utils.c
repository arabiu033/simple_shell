#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the environments variable whose name was given
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *str, *s = NULL;
	str = malloc(sizeof(char) * (_strlen((char *) name) + 1));
	if (!str)
		return (NULL);

	str = _strcat(_strcpy(str, (char *) name), "=");
	while (environ[i])
	{
		s = _strstr(environ[i], str);
		if (s)
		{
			_strtok(s, "=");
			s = _strtok(NULL, "=");
			return (s);
		}
		i++;
	}
	free(str);
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
	static lp *head = NULL;
	char *path, *dir;

	if (head)
		return (head);

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
 *
 * Description: Overwrites the variable if overwrit is non-zero
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value)
{
	int i, j, x, old_len, new_len;
	char **environ_cpy;
	char *str;

	if (_str_upper(name) == 0)
		return (-1);
	if (name == NULL)
	{
		perror("name is NULL");
		return (-1);
	}
	str = malloc(sizeof(char) * (_strlen((char *) name) + 2));
	if (!str)
		return (-1);

	str = _strcat(_strcpy(str, (char *) name), "=");
	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], str))
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
			free(str);
			return (0);
		}
	}
	free(str);
	environ = add_environment(name, value);

	return (0);
}

/**
 * _unsetenv - deletes a the variable name from environment
 * @name: name of the variable to remove
 *
 *
 * Return: 0 on success
 */
int _unsetenv(char *name)
{
	int rmv;
	char *str;

	if (name == NULL)
		return (-1);

	str = malloc(sizeof(char) * (_strlen((char *) name) + 1));
	if (!str)
		return (-1);
	str = _strcat(_strcpy(str, (char *) name), "=");
	for (rmv = 0; environ[rmv]; rmv++)
	{
		if (_strstr(environ[rmv], str))
			break;
	}
	free(str);
	if (environ[rmv] == NULL)
		return (0);

	environ = remove_environment(rmv);
	return (0);
}
