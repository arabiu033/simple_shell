#include "shell.h"

int main(void)
{
	char *s;;

	s = _which("pwd");
	printf("%s\n", s);

	return (0);
}
