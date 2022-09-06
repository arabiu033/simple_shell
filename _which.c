#include "shell.h"

/**
 * _which - replicating the normal shell which
 * @str: passed command to work on
 * Return: full path of the command if exist
 */
char *_which(char *str)
{
	lp *head;

	if (str[0] == '/')
		return (str);

	head = _path_directories_list();
	free_which(head, 1);
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
	int len, new_len = 0;
	lp *head;
	char *path;
	struct stat st;

	head = home;
	while (head)
	{
		len = _strlen(head->s);

		path = strdup(head->s);
		if (!path)
		{
			free_list(home);
			return (NULL);
		}
		new_len = len + 2;
		path = _realloc(path, sizeof(char) * (len + 1), sizeof(char) * new_len);
		if (!path)
		{
			free_list(home);
			return (NULL);
		}
		path = (_strcat(path, "/"));
		len = new_len;
		new_len = len + _strlen(str);
		path = _realloc(path, sizeof(char) * len, sizeof(char) * new_len);
		if (!path)
		{
			free_list(home);
			return (NULL);
		}
		path = (_strcat(path, str));

		if (!stat(path, &st))
			return (path);

		head = head->next;
		free(path);
	}

	return (str);
}

/**
 * free_which - free the linked list used by which
 * @list: the linked-list
 * @sig: signal when to free it
 * Return: void - nothing
 */
void free_which(lp *head, int sig)
{
	static lp *home = NULL;

	if (sig)
	{
		home = head;
		return;
	}

	if (home)
		free_list(home);
}
