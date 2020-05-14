#include "monty.h"

/**
 * print_dlistint - Function that prints all the elements of a dlistint_t list.
 * @h: Header pointer of list.
 * Return: The number of nodes
 */
int print_dlistint(const stack_t *h)
{
	int j = 0;

	while (h != NULL)
	{
		printf("Node %d es %d\n", j, (h->n));
		h = h->next;
		j++;
	}
	return (j);
}
