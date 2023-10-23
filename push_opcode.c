#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Current line number in the Monty bytecode file.
 * @data: data  to be pushed
 */
void push(stack_t **top, unsigned int line_number, char *data)
{
	stack_t *new_node;
	int i = 0;

	if (!data || !is_integer(data))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = atoi(data);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = i;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!*top)
	{
		(*top)->next = new_node;
		new_node->prev = *top;
		*top = new_node;
	}
	else
		*top = new_node;
}
