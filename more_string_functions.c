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
 * _strcomp - compares two strings if they are the same
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 on success
 */
int _strcomp(char *s1, char *s2)
{
	int len_s1 = _strlen(s1), len_s2 = _strlen(s2), i, j;

	if (len_s1 == len_s2)
	{
		for (i = 0; s1[i]; i++)
		{
			if (s1[i] == s2[i])
				j++;
		}
		if (i == j)
			return (1);
	}
	return (0);
}

/**
 * _str-upper - Checks if a string is in uppercase
 * @str: The string
 *
 * Return: 1 if they are the same
 */
int _str_upper(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (_isupper(str[i]) == 0)
		    return (0);
	}

	return (1);
}

/**
 * _isupper - Checks for uppercase character
 * @c: Character
 * Return: 1 if uppercase, otherwise 0.
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
