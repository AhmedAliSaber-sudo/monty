#include "monty.h"
/**
 * execute_operation - Choose Monty ByteCode operation to execute.
 * @top: Pointer to the stack data structure
 * @opcode: The opcode to execute
 * @line_number: line number of opcode
 * @data: to pass to push.
 */
void execute_operation(stack_t **top,
		char *opcode, unsigned int line_number, char *data)
{
	int i = 0;

	instruction_t instructions[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"null", NULL}
	};

	while (instruction_s[i].f)
	{
		if (strcmp("push", opcode) == 0)
		{
			push(top, line_number, data);
			return;
		}
		else if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(top, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
