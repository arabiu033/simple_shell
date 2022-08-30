#include "shell.h"

int main()
{
	char c;

	printf("Enter character: ");
	c = _getc(stdin);
	printf("Character entered: %d", c);

	return (0);
}
