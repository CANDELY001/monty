#include "monty.h"

/**
 * main - Main function.
 * @ac: parameter
 * @av: parameter
 * Return: result
 */
int main(int ac, char *av[])
{
	FILE *file = fopen(av[1], "r");
	int index = 0;
	char *l = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	size_t l_length = 0;
	unsigned int l_number = 1;
	instruction_t command[] = {
		{"push", _push}, {"pall$", _pall}, {NULL, NULL}
	};

	check(ac, av, file);
	while (_getline(&l, &l_length, file) != -1 && !feof(file))
	{
		opcode = strtok(l, " \n");
		if (opcode == NULL)
		{
			l_number++;
			continue;
		}
		while (command[index].opcode != NULL)
		{
			if (strcmp(opcode, command[index].opcode) == 0)
			{
				command[index].f(&stack, l_number);
				break;
			}
			index++;
		}
		if (command[index].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, opcode);
			exit(EXIT_FAILURE);
		} l_number++;
	} free(l);
	free_s(stack);
	fclose(file);
	return (0);
}

