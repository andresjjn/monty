#include "monty.h"

/**
 * op_push - Set nomber to start of stack
 * @stack: Stack pinter
 * @line_number: Line to apply command
 * Return: -
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
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
