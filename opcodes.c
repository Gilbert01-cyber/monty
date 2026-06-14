#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int n, i;

	arg = strtok(NULL, " \t\n\r");

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(g_line);
		fclose(g_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Validate that arg is a valid integer */
	i = 0;
	if (arg[0] == '-')
		i = 1;
	for (; arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(g_line);
			fclose(g_file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(g_line);
		fclose(g_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * op_pall - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(g_line);
		fclose(g_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(g_line);
		fclose(g_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(g_line);
		fclose(g_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
