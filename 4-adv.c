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
/**
 * _div - Divides the top two elements of the stack
 * @stack: Stack
 * @line_n: Line Number
 * Return: Boid
*/
void _div(stack_t **stack, unsigned int line_n)
{
	int nm;

	if (!*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	nm = (*stack)->next->n;
	if (nm == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_n);
		exit(EXIT_FAILURE);
	}
	nm = nm / (*stack)->n;
	_pop(stack, line_n);
	(*stack)->n = nm;
}
