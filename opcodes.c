#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
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

void free_stack(stack_t *stack)
{
    stack_t *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

void push(stack_t **stack, unsigned int line_number)
{
    /* Ensure your push logic handles integer conversion and malloc checks */
    (void)stack;
    (void)line_number;
}
