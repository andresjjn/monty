#include "monty.h"

/**
 * op_rotl - The opcode rotl rotates the stack to the top.
 * @stack: Header pointer of list.
 * @line_number: This line number of the file.m
 * Return: Nothing
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *head, *elem;
    unsigned int n_nodes = 0;

    (void)line_number;
	current = *stack;
    if (current == NULL)
    {
		printf("L%u: can't pint, stack empty\n", line_number);
		_puts2("EXIT_FAILURE\n");
		exit(EXIT_FAILURE);
    }
    while (current->next != NULL)
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

    head = (*stack)->next;
    head->prev = NULL;
    elem = *stack;
    elem->next = NULL;
    current->next = elem;
    elem->prev = current;
    *stack = head;
}
