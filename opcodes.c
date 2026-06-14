#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: script line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * push - adds a new node to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
    /* Your existing push implementation goes here */
}

/**
 * pall - prints all elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
    /* Your existing pall implementation goes here */
}

/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the head of the stack
 */
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
