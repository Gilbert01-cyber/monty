#define _GNU_SOURCE
#include "monty.h"

FILE *g_file = NULL;
char *g_line = NULL;

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * main - entry point for the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	char *opcode;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{NULL, NULL}
	};
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	g_file = fopen(argv[1], "r");
	if (!g_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&g_line, &len, g_file) != -1)
	{
		line_number++;
		opcode = strtok(g_line, " \t\n\r");

		if (!opcode || opcode[0] == '#')
			continue;

		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opcode);
			free(g_line);
			fclose(g_file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	free(g_line);
	fclose(g_file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
