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
 * get_line - reads a line from a file into a global buffer
 * @line_buf: pointer to the buffer
 * @file: file to read from
 * Return: pointer to the line or NULL on EOF/error
 */
char *get_line(char **line_buf, FILE *file)
{
	static char buf[1024];

	if (!fgets(buf, sizeof(buf), file))
		return (NULL);
	*line_buf = buf;
	return (buf);
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
	char *opcode;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{"add", op_add},
		{"nop", op_nop},
		{"div", op_div},
		{"sub", op_sub},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
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

	while (get_line(&g_line, g_file))
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
			fclose(g_file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	fclose(g_file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
