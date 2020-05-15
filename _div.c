#include "monty.h"

/**
 * op_div - The opcode div divides the second top element of the stack by
 * the top element of the stack.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next;
    unsigned int n_nodes = 0;

    (void)line_number;
	current = *stack;
    if (current == NULL)
    {
		printf("L%u: can't pint, stack empty\n", line_number);
		_puts2("EXIT_FAILURE\n");
		exit(EXIT_FAILURE);
    }
    while (current != NULL)
    {
        n_nodes++;
        current = current->next;
    }
    if (n_nodes < 2)
    {
        printf("L%u: can't swap, stack too short\n", line_number);
		_puts2("EXIT_FAILURE\n");
		exit(EXIT_FAILURE);
    }
    current = *stack;
    if (current->n == 0)
    {
        printf("L%u: division by zero\n", line_number);
		_puts2("EXIT_FAILURE\n");
		exit(EXIT_FAILURE);
    }
    next = current->next;
    next->prev = NULL;
    next->n = next->n / current->n;
    *stack = next;
    free(current);
}
