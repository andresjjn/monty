#include "monty.h"

/**
 * op_pchar - The opcode pchar prints the char at the top of the
 * stack, followed by a new line.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

    (void)line_number;
	current = *stack;
    if (current == NULL)
    {
		printf("L%u: can't pint, stack empty\n", line_number);
		_puts2("EXIT_FAILURE\n");
		exit(EXIT_FAILURE);
    }
	while (current == *stack)
	{
		printf("%c\n", (current->n));
		current = current->next;
	}
}
