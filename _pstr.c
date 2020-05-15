#include "monty.h"

/**
 * op_pstr - The opcode pint prints the value at the top of the stack, 
 *followed by a new line.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

    (void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%c\n", (current->n));
		current = current->next;
	}
}
