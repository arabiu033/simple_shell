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
	puts("1235");
	head = _path_directories_list();
	printf("-----g");
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
	int start = 1, new_len, old_len, n, o;
	lp *head;
	char *s, *path;
	struct stat st;

	head = home;
	while (head)
	{
		new_len = _strlen(head->s) + _strlen(str) + 2;
		n = _strlen(head->s) + 1;

		if (start)
		{
			path = malloc(sizeof(char) * new_len);
			s = malloc(sizeof(char) * n);
			start = 0;
		}
		else
		{
			path = _realloc(path, sizeof(char) * old_len, sizeof(char) * new_len);
			s = _realloc(s,  sizeof(char) * o, sizeof(char) * n);
		}

		s = head->s;
		path = _strcat(_strcat(s, "/"), str);

		if (!stat(s, &st))
		{
			*free(s);
			free_list(home);
			return (path);
		}

		head = head->next;
		old_len = new_len;
		o = n;
	}

	free(s);
	free(path);
	free_list(home);
	return (str);
}
