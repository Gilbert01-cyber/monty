#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
{
    line_number++;
    opcode = strtok(line, " \n\t");

    if (!opcode || opcode[0] == '#')
        continue;

    /* Handle push specifically to capture the argument */
    if (strcmp(opcode, "push") == 0)
{
    char *arg = strtok(NULL, " \n\t");
    push(&stack, line_number, arg);
}
    else if (strcmp(opcode, "pall") == 0)
        pall(&stack, line_number);
    else if (strcmp(opcode, "pint") == 0)
        pint(&stack, line_number);
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

	free(line);
	free_stack(stack);
	fclose(file);

	return (0);
}
