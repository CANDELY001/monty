#include "monty.h"

/**
 * _sub - Subtract the top and second top elements of the stack
 * @stack: Stack
 * @line_n: Line Number
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_n)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
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
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	} num = (*stack)->next->n;
	if (num == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_n);
		exit(EXIT_FAILURE);
	} num = num / (*stack)->n;
	_pop(stack, line_n);
	(*stack)->n = num;
}
