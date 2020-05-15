#include "monty.h"

/**
 * op_pop - The opcode pop removes the top element of the stack.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next;

	(void)line_number;
	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;

	if (next != NULL)
	{
		next->prev = NULL;
		*stack = next;
		free(current);
	}
	else
	{
		free(current);
	}
}
