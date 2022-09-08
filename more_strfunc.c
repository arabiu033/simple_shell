#include "shell.h"

/**
 * print_number - prints an integer
 * @n: The integer
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int holder = 1, dummy = n, x;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
		dummy = n;
	}

	while (dummy > 9)
	{
		dummy = dummy / 10;
		holder = holder * 10;
	}

	while (holder != 0)
	{
		x = n / holder;
		n = n % holder;
		holder = holder / 10;
		_putchar('0' + x);
	}
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: outputs the difference of s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _strdup - Creates a duplicate of a string on the heap
 * @str: The string
 *
 * Return: The duplicated of str
 */
char *_strdup(char *str)
{
	int i, len;
	char *dup;

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
