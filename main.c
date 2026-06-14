/* ... inside your while(getline...) loop ... */
    if (strcmp(opcode, "push") == 0)
    {
        char *arg = strtok(NULL, " \n\t");
        push(&stack, line_number, arg);
    }
    else if (strcmp(opcode, "pall") == 0)
        pall(&stack, line_number);
    else if (strcmp(opcode, "pint") == 0)
        pint(&stack, line_number);
    else if (strcmp(opcode, "pop") == 0)
        pop(&stack, line_number);
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
