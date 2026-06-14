#include "monty.h"

/**
 * is_number - checks if a string is a valid integer
 * @s: string to check
 * Return: 1 if number, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	if (!s) return (0);
	if (s[0] == '-') i++;
	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9') return (0);
	}
	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg = strtok(NULL, " \n\t");

	if (!is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: pointer to the head of the list
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
