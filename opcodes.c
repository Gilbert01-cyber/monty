/**
 * is_digit - checks if a string is a number
 * @s: string to check
 * Return: 1 if number, 0 if not
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	if (s[0] == '-')
		i++;
	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	stack_t *new_node;

	if (!is_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* ... rest of your malloc and link logic ... */
}
