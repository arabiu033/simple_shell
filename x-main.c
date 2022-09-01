#include "shell.h"

int main()
{
	int i;

	_setenv("HOME", "wireless");

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	_putchar('\n');

	_unsetenv("HOME");

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (0);
}
