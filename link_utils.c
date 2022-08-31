#include "shell.h"

/**
 * linked_list - adds a node at the end of a linked list
 * @head: head pointer
 * @str: string
 *
 * Return: address to the new element
 */
lp *linked_list(lp **head, const char *str)
{
	lp *new;

	new = malloc(sizeof(lp));
	if (new == NULL)
		return (NULL);
	new->s = strdup(str);
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		lp *last = *head;

		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}

	return (new);
}

/**
 * free_list - frees a lp linked list
 * @head: pointer to the start of the list
 *
 * Return: void
 */
void free_list(lp *head)
{
	lp *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->s);
		free(current);
		current = next;
	}

}
