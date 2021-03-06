#include "monty.h"

/**
 * op_mod - The opcode mod computes the rest of the division of the second top
 *element of the stack by the top element of the stack.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->prev = NULL;
	next->n = next->n % current->n;
	*stack = next;
	free(current);
}
