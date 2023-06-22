#include "monty.h"

/* BY CHARIFA MASBAHIA */
/**
 * is_num - Checks if a string is a number
 * @s: String
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_num(char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;
		if (_isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * _push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Line Number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *argument;
	stack_t *new_node = malloc(sizeof(stack_t));

	argument = strtok(NULL, " \n\t ");
	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(argument);
	if (is_num(argument) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * _pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line Number (unused)
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
