#include "monty.h"

char **read_file(const char *filename)
{
        int fd, j = 1;
        int letters = 0;
	unsigned int i = 0;
	ssize_t _read;
	char *buffer, **cmd = NULL;
	struct stat st;

	stat(filename, &st);
	letters = st.st_size;
	if (filename == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY, 600);
	if (fd == -1)
        {
                printf("Error: Can't open file %s\n", filename);
                _puts2("EXIT_FAILURE\n");
                exit(98);
        }
	buffer = (char *)malloc(letters + 1 * sizeof(char));
	if (buffer == NULL)
	{
		printf("Error: malloc failed");
		_puts2("EXIT_FAILURE\n");
                exit(98);
	}
	_read = read(fd, buffer, letters);
	if (_read == -1)
		return (NULL);
	buffer[letters + 1] = '\0';
	for (i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n' || buffer[i] == '\0')
			j++;
	cmd = strtok_cmd(buffer, j);
	close(fd);
	return (cmd);
}

/**
 * strtok_cmd - PID
 * @arg: line buffer from getline
 * @cmd: pointer to command empty space
 * Return: Nothing.
 */
char **strtok_cmd(char *buffer, int j)
{
	int i = 0;
	char *tok = 0;
	char **cmd;

	cmd = malloc(sizeof(char *) * (j + 1));
	if (cmd == NULL)
	{
		printf("Error: malloc failed");
		_puts2("EXIT_FAILURE\n");
                exit(98);
	}
	tok = strtok(buffer, "\n\t");
	while (i < j)
	{
		cmd[i] = malloc(sizeof(char *));
		if (cmd == NULL)
		{
			printf("Error: malloc failed");
			_puts2("EXIT_FAILURE\n");
        		exit(98);
		}
		cmd[i] = tok;
		tok = strtok(0, "\n\t");
		i++;
	}
	cmd[i] = NULL;
	return(cmd);
}
