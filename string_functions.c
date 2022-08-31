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
 * _strstr - locates a substring in a string
 * @needle: substring
 * @haystack: string *
 * Return: a pointer to needle in haystack
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && (haystack[i] == needle[0]))
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break;
		}
		if (needle[j])
		{
			i++;
			j = 0;
		}
		else
			return (haystack + i);
	}
	return (0);
}

/**
 *_strcat - concatenates  the string pointed to by @src to
 * the end of the string pointed to by @dest
 *@dest: String that will be appended
 *@src: String to be concatenated upon
 *
 * Return: returns poiner to @dest
 */

char *_strcat(char *dest, char *src)
{

	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];

	return (dest);
}

/**
 * _strcpy - copies a string
 * @src: copy from
 * @dest: copy to
 *
 * Return: returns src
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
