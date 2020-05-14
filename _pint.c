#include "monty.h"

/**
 * op_pint - The opcode pint prints the value at the top of the stack, 
 *followed by a new line.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

    (void)line_number;
	current = *stack;
    if (current == NULL)
    {
		fprintf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
    }
	while (current == *stack)
	{
		printf("%d\n", (current->n));
		current = current->next;
	}
}
