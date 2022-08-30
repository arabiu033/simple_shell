#include "shell.h"

/**
 * strcomp - compares two strings if they are the same
 * @s1: string 1 (NULL terminated)
 * @s2: string 2 (NULL terminated)
 *
 * Return: 0 if equal
 */
int _strcomp(char *s1, char *s2)
{
	int i, len_1 = _strlen(s1), len_2 = _strlen(s2);

	if (len_1 == len_2)
	{
		for (i = 0; s1[i] == s2[i]; i++)
			;
		if (i == len_1)
			return (0);
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of string s
 */

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
		++x;

	return (x);
}
