#include "monty.h"
/**
 * _swap - Swaps the top two elements of the stack
 * @stack: Stack
 * @line_n: Line Number
 */

void _swap(stack_t **stack, unsigned int line_n)
{
	stack_t *nm;
	int change;

	nm = *stack;
	if (nm == NULL || nm->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	} change = nm->n;
	nm->n = nm->next->n;
	nm->next->n = change;
}
/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_n: Line Number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (!*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n;
	sum += (*stack)->n;
	_pop(stack, line_n);
	(*stack)->n = sum;
}
/**
 * _nop - doesn’t do anything
 * @stack: pointer to the stack
 * @line_n: line number
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}
