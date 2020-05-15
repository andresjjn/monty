#include "monty.h"

/**
 * inter - Interpreter of funtions.
 * @cmd: pointer of commands and args.
 * Return: 1 if works
 */
int inter(char **cmd)
{
	int i = 0;
	unsigned int arg = 0;
	char *command = NULL, *ptr_str = NULL;
	stack_t *stack = NULL;

	if (!cmd)
		return (0);
	while (cmd[i])
	{
		arg = 0;
		ptr_str = NULL;
		command = strtok(cmd[i], " ");
		ptr_str = strtok(0, " ");
		if (ptr_str)
			arg = atoi(ptr_str);
		get(command, i + 1)(&stack, arg);
		i++;
	}
	free_argument(cmd);
	free_list(stack);
	return (0);
}
