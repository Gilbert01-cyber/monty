
#include "monty.h"

/* Global variable to hold the integer value for push */
int global_val = 0;

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *arg = strtok(NULL, " \n\t");

    /* Validate that an integer was provided */
    if (!arg || atoi(arg) == 0 && strcmp(arg, "0") != 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;
    
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
