#include "monty.h"

/**
 * _puts2 - print string.
 * @str: string.
 * Return: Nothing.
 */
void _puts2(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar2(str[i]);
}
/**
 * _putchar2 - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar2(char c)
{
	return (write(2, &c, 1));
}

/**
 * free_cmd - free all mallocs.
 * @cmd: pointer to free.
 */
void free_cmd(char **cmd)
{
	int i = 0;

	if (!cmd)
		return;
	while (cmd[i])
	{
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
	free(cmd);
	cmd = NULL;
}
/**
 * free_argument - free all mallocs.
 * @cmd: pointer to free.
 */
void free_argument(char **cmd)
{
	int i = 0;

	if (!cmd)
		return;
	while (cmd[i])
	{
		free(cmd[i]);
		cmd[i++] = NULL;
	}
	free(cmd);
	cmd = NULL;
}

/**
 * simple_free - free a pointer
 * @buffer: pointer to free.
 */
void simple_free(char **buffer)
{
	if (buffer[0])
	{
		free(buffer[0]);
		buffer[0] = NULL;
	}
}
