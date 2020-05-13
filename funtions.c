#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed");
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}

	new->n = line_number;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
	       tmp = *stack;

		if (tmp != NULL)
			tmp->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}

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
