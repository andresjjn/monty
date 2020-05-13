#include "monty.h"

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
                {
                        printf("ptr_str = %s\n", ptr_str);
                        arg = atoi(ptr_str);
                        printf("arg = %d\n", arg);
                }
                printf("arg = %d\n", arg);
                printf("Comando = %s y el argumento es = %d\n", command, arg);
                get_op_func(command, i + 1, cmd)(&stack, arg);
                
                i++;
        }
        print_dlistint(stack);
        free(cmd);
        return(1);
}
