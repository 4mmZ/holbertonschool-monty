#include "monty.h"

int is_int(char *s)
{
    int i = 0;

    if (s == NULL)
        return (0);

    if (s[0] == '-' || s[0] == '+')
        i = 1;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
    }

    return (1);
}

void push_func(stack_t **stack, unsigned int line_number)
{
        char *arg = strtok(NULL, DELIM);
        int n;

        if (!arg || !is_int(arg))
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        n = atoi(arg);
        add_node(stack, n);
}

void pall_func(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;

        (void)line_number;

        while (tmp)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}

void add_node(stack_t **stack, int n)
{
        stack_t *new_node = malloc(sizeof(stack_t));

        if (!new_node)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack)
                (*stack)->prev = new_node;

        *stack = new_node;
}