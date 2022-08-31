#include "shell.h"

/**
 * _puts - prints a string to stdout
 * @str: The string
 */

void _puts(char *str)
{
	int i;
	char ch;

	i = 0;
	while (str[i] != '\0')
	{
		ch = str[i];
		_putchar(ch);
		++i;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _getc - Reads a character from file stream
 * @stream: file stream to read from
 *
 * Return: The character read
 */
char _getc(__attribute__((unused)) FILE *stream)
{
	char c;

	read(0, &c, 1);

	return (c);
}

/**
 * error_message - prints error message for invalid command
 * @p: process number
 */
void error_message(int p, char *s, char *cmd)
{
	_puts(s);
	_puts(": ");
	print_number(p);
	_puts(": ");
	_puts(cmd);
	_puts("not found\n");
}
