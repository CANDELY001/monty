#include "monty.h"

/**
 * free_stack - Frees the stack
 * @head: Stack Head
 */

void free_s(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
/**
 * check - Checks if the arguments are correct.
 * @ac: parameter
 * @av: parameter
 * @file: File
 */

void check(int ac, char *av[], FILE *file)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

}
