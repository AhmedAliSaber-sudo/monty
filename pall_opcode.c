#include "monty.h"

/**
 * pall - Prints all the values on the stack starting from the top of the stack
 *
 * @top: Pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */

void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
