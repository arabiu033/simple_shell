#include "shell.h"

int main()
{
	int i;

	_setenv("BOSS", "wireless", 1);

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	    return (0);
}
