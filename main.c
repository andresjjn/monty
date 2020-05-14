#include "monty.h"

/**
 * main - opcode and its function
 * @argc: Number of arguments
 * @argv: Dolbe pointer of args.
 * Return: 0
 */
int main(int argc, char const *argv[])
{
	char **cmd = NULL;

	if (!argv[1] || argc > 2)
	{
		printf("USAGE: monty file\n");
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}
	if (strcmp(argv[1] + (strlen(argv[1]) - 2), ".m") != 0)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}
	cmd = read_file(argv[1]);
	inter(cmd);
	return (0);
}
