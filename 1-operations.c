#include "monty.h"

/* BY CHARIFA MASBAHIA */
/**
 * is_num - Checks if a string is a number
 * @s: String
 * Return: 1 if the string is a number, 0 otherwise
 */

int is_num(char *s)
{
	int i = 0;

	s = strtok(s, " \n");
	if (s[0] == '-')
		i++;
	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	} return (0);
}

/**
 * _push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Line Number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int nm;
	char *argument;
	stack_t *new_node = malloc(sizeof(stack_t));

	argument = strtok(NULL, " \n\t");
	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	nm = atoi(argument);
	if (is_num(argument) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = nm;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}
/**
 * _pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line Number (unused)
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *curr;

	for (curr = *stack; curr != NULL; curr = curr->next)
		printf("%d\n", curr->n);
}
