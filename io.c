#include "monty.h"

/**
 * read_file - read a file, create a buffer with contet.
 * @filename: Pointer of file name.
 * Return: The new double pointer with monty bytecode.
 */
char **read_file(const char *filename)
{
	int fd = 0;
	unsigned int letters = 0;
	ssize_t _read = 0;
	char *buffer = NULL, **cmd = NULL;

	letters = fsize(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}
	buffer = malloc(sizeof(char) * (letters + 1));
	if (!buffer)
	{
		printf("Error: malloc failed");
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}
	_read = read(fd, buffer, letters);
	if (_read == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		_puts2("EXIT_FAILURE\n");
		exit(98);
	}
	buffer = clean_string(buffer, letters + 1);
	cmd = split_string(buffer, '\n');
	close(fd);
	return (cmd);
}

/**
 * split_string - divide a string into several within a double pointer.
 * @buffer: string.
 * @d: delimiter.
 * Return: The new double pointer.
 */

char **split_string(char *buffer, char d)
{
	int i = 0, j = 1, k = 0, len = 0, n  = 0, f = 0;
	char **cmd = NULL;

	n = strlen(buffer);
	if (buffer[0] == '#' && d == ' ')
		return (cmd);
	for (f = 0; buffer[f] && (((d != ' ' || (buffer[f + 1] &&
	buffer[f + 1] != '#'))) || buffer[f] != ' '); f++)
		j++;
	cmd = malloc(sizeof(char *) * (j + 1));
	if (!cmd)
		return (NULL);
	for (len = 0, i = 0; i < n && buffer[i] && i <= f; i++)
	{
		len = 0;
		j = i;
		for (; buffer[j] && (buffer[j] != d);)
			len++, j++;
		cmd[k] = malloc(sizeof(char) * (len + 1));
		if (!cmd[k])
		{
			free_argument(cmd);
			return (NULL);
		}
		for (j = 0; buffer[i] && (buffer[i] != d); i++, j++)
			cmd[k][j] = buffer[i];
		cmd[k][j] = 0;
		k++;
		cmd[k] = NULL;
	}
	return (cmd);
}

/**
 * clean_string - Clean the string of spaces and new line.
 * @tmp: String to clean.
 * @len: Len of the string.
 * Return: the new string.
 */
char *clean_string(char *tmp, int len)
{
	char *new = NULL;
	char *buffer = NULL;
	int i = 0, j = 0, k = 0, t = 0;

	buffer = tmp;
	while (buffer[i] == ' ' || buffer[i] == '\t')
		i++, k++;
	for (t = 0; buffer[t]; t++)
		if (buffer[t] == '\t')
			buffer[t] = ' ';
	for (t = i; buffer[t]; t++)
		if (buffer[t] == ' ' && buffer[t + 1] == ' ')
			k++;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == ' ')
		{
			if (buffer[i + 1] == '\0' || buffer[i + 1] == 0)
				break;
			if (buffer[i + 1] == ' ')
			{
				i++;
				continue;
			}
		}
		if (buffer[i] != '\0' && !new)
		{
			new = malloc((len - k) * sizeof(char));
			if (!new)
				return (NULL);
		}
		if (buffer[i] != '\0')
			new[j] = buffer[i], j++, i++;
		else
			i++;
	}
	simple_free(&buffer);
	if (new)
		new[j] = 0;
	return (new);
}

/**
 * fsize - Size of a file.
 * @file: Pointer of file name.
 * Return: size or -1 if error.
 */
unsigned int fsize(const char *file)
{
	unsigned int size;
	FILE *fh;

	fh = fopen(file, "rb");
	if (fh != NULL)
	{
		if (fseek(fh, 0, SEEK_END))
		{
			fclose(fh);
			return (-1);
		}
		size = ftell(fh);
		fclose(fh);
		return (size);
	}
	return (-1);
}
