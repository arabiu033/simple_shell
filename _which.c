#include "shell.h"

/**
 * _which - replicating the normal shell which
 * @str: passed command to work on
 * Return: full path of the command if exist
 */
char *_which(char *str)
{
	lp *head;

	if (*str == '/')
		return (str);

	head = _path_directories_list();
	return (_pathFinder(head, str));

}

/**
 * _pathFinder - searches for the right path
 * @home: the head of the linked list
 * @str: the command passed
 * Return: full path is function is succesful
 */
char *_pathFinder(lp *home, char *str)
{
	int len, new_len;
	lp *head;
	char *path;
	struct stat st;

	head = home;
	while (head)
	{
		len = _strlen(head->s);

		path = strdup(head->s);
		new_len = len + 2;
		path = _realloc(path, sizeof(char) * len, sizeof(char) * new_len);
		path = (_strcat(path, "/"));
		len = new_len;
		new_len = len + _strlen(str);
		path = _realloc(path, sizeof(char) * len, sizeof(char) * new_len);
		path = (_strcat(path, str));

		if (!stat(path, &st))
		{
			/* free_list(home); */
			return (path);
		}

		head = head->next;
		free(path);
	}


	/* free_list(home); */
	return (str);
}
