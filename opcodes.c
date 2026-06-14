#include "monty.h"

int is_number(char *str)
{
    if (!str) return (0);
    if (*str == '-') str++;
    if (*str == '\0') return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9') return (0);
        str++;
    }
    return (1);
}

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;

    if (!is_number(arg))
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
    stack_t *current = *stack;
    (void)line_number;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void free_stack(stack_t *stack)
{
    stack_t *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    /* ... your existing pint function ... */
void pint(stack_t **stack, unsigned int line_number)
{
    /* ... your code ... */
}

/* ADD THE POP FUNCTION HERE */
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: script line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(tmp);
}

/* ... then your free_stack and other functions ... */
void free_stack(stack_t *stack)
{
    /* ... */
}
}
