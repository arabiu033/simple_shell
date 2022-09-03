#include "shell.h"

int main(void)
{
	char *s;;

	puts("--T--");
	s = _which("/ls");
	printf("%s\n", s);

	return (0);
}
