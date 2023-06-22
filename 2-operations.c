#include "monty.h"
/* BY CHARIFA MASBAHI */
/**
 * _pint - Prints the value at the top of the stack
 * @stack: Stack
 * @line_n: Line Number
 */
void _pint(stack_t **stack, __attribute__ ((unused))unsigned int line_n)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
        }

	printf("%d\n", (*stack)->n);
}
/**
 * _pop - Removes the top element of the stack
 * @stack: Stack
 * @line_n: Line Number
 * Return: result
 */
void _pop(stack_t **stack, unsigned int line_n)
{
	stack_t *t;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(t);
}
