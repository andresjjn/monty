#include "monty.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: Operator passed as argument to the program
 * @f: Function pointer
 * Return: -
 */
void (*get_op_func(char *command, int line, char **cmd))(stack_t **stack, unsigned int line_number)
{
       	int i = 0;

	instruction_t ops[] = {
		{"push", op_push},
		{NULL, NULL}
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, command) == 0)
                {        
                        return(ops[i].f);
                }
		i++;
	}
        printf("L%d: unknown instruction %s\n", line, command);  
        _puts2("EXIT_FAILURE\n");
        free(cmd);
        exit(98);
}
