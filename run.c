#include "monty.h"

/**
 * run - run the Monty bytecode interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS if the program
 * executes successfully, otherwise EXIT_FAILURE.
 */

int run(int argc, char **argv)
{
	stack_t *top = NULL;
	FILE *monty_file = NULL;
	char line[1024];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), monty_file))
	{
		char *opcode, *data;

		opcode = strtok(line, " \t\n");
		data = strtok(NULL, " \t\n");
		if (opcode[0] == '#')
			continue;
		line_number++;
		if (opcode)
			execute_operation(&top, opcode, line_number, data);
	}
	while (top)
	{
		stack_t *temp = top;

		top = stack->prev;
		free(temp);
	}
	fclose(monty_file);
	return (0);
}
