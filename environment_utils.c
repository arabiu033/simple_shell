#include "shell.h"

void env_dum(void);

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variables
 *
 * Return: the value of the environments variable whose name was given
 */
char *_getenv(const char *name)
{
	int i = 0, len;
	char *str, *s = NULL, *ss;

	str = malloc(sizeof(char) * (_strlen((char *) name) + 1));
	if (!str)
		return (NULL);

	str = _strcat(_strcpy(str, (char *) name), "=");
	while (environ[i])
	{
		s = strstr(environ[i], str) && environ[i][0] == str[0] ?
			strstr(environ[i], str) : NULL;

		if (s)
		{
			len = _strlen(s);
			ss = malloc(sizeof(char) * (len + 1));
			if (!ss)
				return (NULL);

			for (i = 0; i < len; i++)
				ss[i] = s[i];
			ss[i] = '\0';

			_strtok(ss, "=");
			ss = _strtok(NULL, "=");
			free(str);
			return (ss);
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
	if (!path)
		return;
	dir = _strtok(path, ":");
	while (dir)
	{
		_puts(dir);
		_puts("\n");
		dir = _strtok(NULL, ":");
	}
	free(path);
}

lp *head = NULL;
/**
 * _path_directories_list - build the linkedlist of path directories
 * Return: lp - linked list of the path directoies
 */
lp *_path_directories_list(void)
{
	char *path, *dir;

	if (head)
		return (head);

	path = _getenv("PATH");
	if (!path)
		return (NULL);
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
	char *str;

	if (!name || _strlen(name) == 0 || _strstr(name, "="))
	{
		errno = EINVAL;
		perror("_setenv");
		return (-1);
	}

	str = malloc(sizeof(char) * (_strlen((char *) name) + 2));
	if (!str)
	{
		errno = ENOMEM;
		perror("_setenv");
		return (-1);
	}

	str = _strcat(_strcpy(str, (char *) name), "=");
	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], str) && environ[i][0] == str[0] ?
		    _strstr(environ[i], str) : NULL)
		{
			j = _strlen(name) + 1;
			new_len = j + _strlen(value);
			old_len = _strlen(environ[i]) + 1;
			environ[i] = _realloc(environ[i], old_len * sizeof(char),
						  (new_len + 1) * sizeof(char));
			if (environ[i] == NULL)
			{
				errno = ENOMEM;
				perror("_setenv");
				return (-1);
			}
			for (x = 0; value[x]; x++)
			{
				environ[i][j] = value[x];
				j++;
			}
			environ[i][j] = '\0';
			free(str);
			return (0);
		}
	}
	free(str);
	add_environment(name, value);
	if (environ == NULL)
	{
		errno = ENOMEM;
		perror("_setenv");
		return (-1);
	}

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

	if (_strlen(name) == 0 || _strstr(name, "="))
	{
		errno = EINVAL;
		perror("_unsetenv");
		return (-1);
	}

	str = malloc(sizeof(char) * (_strlen((char *) name) + 2));
	if (!str)
		return (-1);
	str = _strcat(_strcpy(str, (char *) name), "=");
	for (rmv = 0; environ[rmv]; rmv++)
	{
		if (_strstr(environ[rmv], str) && environ[rmv][0] == str[0] ?
		    _strstr(environ[rmv], str) : NULL)
			break;
	}
	free(str);
	if (environ[rmv] == NULL)
		return (0);

	remove_environment(rmv);
	return (0);
}

/**
 * env_dum - to bypass betty
 */
void env_dum(void)
{
}
