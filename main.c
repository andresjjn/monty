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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1] + (strlen(argv[1]) - 2), ".m") != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	cmd = read_file(argv[1]);
	inter(cmd);
	return (0);
}
