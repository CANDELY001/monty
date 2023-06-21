#include "monty.h"
/* BY CHARIFA MASBAHI */
/**
 * _pint - Prints the value at the top of the stack
 * @stack: Stack
 * @line_n: Line Number
 */
void _pint(stack_t **stack, __attribute__ ((unused))unsigned int line_n)
{
	stack_t *num;

	num = *stack;
	if (!num)
	{
		printf("L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", num->n);
}
