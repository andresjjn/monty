#include "monty.h"

/**
 * get - Selects the correct function to perform the operation
 * @command: Operator passed as argument to the program
 * @line: Line to apply command
 * Return: -
 */
void (*get(char *command, int line))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL}
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, command) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
	free(command);
	exit(EXIT_FAILURE);
}
