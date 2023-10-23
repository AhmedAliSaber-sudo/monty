#include "monty.h"

/**
 * pop - removes the top node of the stack.
 *
 * @top: Pointer to the top node of the stack.
 * @line_number: The line number in the Monty file.
 */

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *top;
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->prev == NULL)
	{
		*top = NULL;
	}
	else
	{
		(*top)->prev->next = NULL;
		*top = (*top)->prev;
	}
	free(tmp);
}
