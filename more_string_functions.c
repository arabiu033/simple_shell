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
