#include "shell.h"

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

/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character
 *
 * Return: a pointer to the first occurence of the character
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		if (*(s + i) == c)
			return (s + i);
	}
	if (*(s + i) == c)
		return (s + i);
	return (0);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string
 * @accept: string
 *
 * Return: pointer to the byte in s that matches
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				break;
			}
		}
		if (accept[j])
			return (s + i);
	}
	return (0);
}
