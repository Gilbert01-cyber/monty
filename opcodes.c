#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: script line number
 */
void push(stack_t **stack, unsigned int line_number)
{
    /* 1. Logic: Parse the integer argument (often handled in main) */
    /* 2. Allocate memory for a new node */
    /* 3. Set the value, link the new node to the top, and update the head */
    (void)stack;
    (void)line_number;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: script line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
