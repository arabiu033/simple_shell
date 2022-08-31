#include "shell.h"

/**
 * _printenv - print the environment variables
 * Return: void - nothing
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i])
		_puts(environ[i++]);
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

	str = malloc(sizeof(char) * (_strlen(name) + 1));
	str = _strcat(_strcpy(str, name), "=");
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
		printf("%s\n", dir);
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
