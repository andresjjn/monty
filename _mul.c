#include "monty.h"

/**
 * op_mul - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next;
	unsigned int n_nodes = 0;

	(void)line_number;
	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		n_nodes++;
		current = current->next;
	}

	if (n_nodes < 2)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	next = current->next;
	next->prev = NULL;
	next->n = next->n * current->n;
	*stack = next;
	free(current);
}
