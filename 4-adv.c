#include "monty.h"

/**
 * _sub - Subtract the top and second top elements of the stack
 * @stack: Stack
 * @line_n: Line Number
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_n)
{
	stack_t *nm;
	int sub;

	nm = *stack;
	if (!nm || nm->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	sub = nm->next->n - nm->n;
	nm->next->n = sub;
	_pop(stack, line_n);
}
