#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **read_file(const char *filename);
char **strtok_cmd(char *buffer, int j);
int inter(char **cmd);
void _puts2(char *str);
int _putchar2(char c);
void (*get_op_func(char *command, int line, char **cmd))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void free_cmd(char **cmd);
long int findSize(char file_name[]);
int print_dlistint(const stack_t *h);

#endif /* MONTY_H */
