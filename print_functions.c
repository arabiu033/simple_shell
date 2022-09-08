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
 * error_message - prints error message for invalid command
 * @p: process number
 * @s: the shell name
 * @cmd: t\The command passed
 */
void error_message(int p, char *s, char *cmd)
{
	_puts(s);
	_puts(": ");
	print_number(p);
	_puts(": ");
	_puts(cmd);
	_puts(" not found\n");
}

/**
 * invalid_file - prints error message if file does not exist
 * @s1: the shell name
 * @s2: the shell first argument (filename)
 */
void invalid_file(char *s1, char *s2)
{
	_puts(s1);
	_puts(": ");
	_putchar('0');
	_puts(": ");
	_puts("Cant't open ");
	_puts(s2);
	_putchar('\n');
}
