#include <stdio.h>

lp linked_list(char *str)
{

	lp *head, *new, *last;
	int n = 1;
	char *buf;

	buf = strtok(str, ":");
	while (buf)
	{
		new = malloc(sizeof(lp));
		new->s = strdup(buf);
		new->next = NULL;

		if (n)
		{
			head = new;
			last = head;
			n = 0;
		}
		else
		{
			last->next = new;
			last = new;
		}
		buf = strtok(NULL, ":");
	}

	return (head);
}
