#include "monty.h"

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

/**
 *free_list - free the memory space in a linked list
 *@head: head of the linked list
 */

void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head  = tmp;
	}
	free(head);
}

/**
 *print_listint - prints a given singly linked list
 *@h: head of the singly linked list
 *Return: the number of nodes of the list
 */
size_t print_listint(const stack_t *h)
{
	int j = 0;

	while (h != NULL)
	{
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * _malloc - prints malloc error and exit
 */
void _malloc(void)
{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
