#include "monty.h"

/**
 * main - Main function.
 * @ac: parameter
 * @av: parameter
 * Return: result
 */
int main(int ac, char **av)
{
	FILE *file = fopen(av[1], "r");
	int index = 0;
	char *l = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	size_t l_length = 0;
	unsigned int l_number = 1;
	instruction_t command[] = {
		{"push", _push}, {"pall", _pall},
	       	{"pint", _pint}, {"pop", _pop}, 
		{"swap", _swap}, {"add", _add}, 
		{"nop", _nop}, {NULL, NULL}
	};

	check(ac, av, file);
	while (_getline(&l, &l_length, file) != -1 && !feof(file))
	{
		opcode = strtok(l, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
		{
			l_number++;
			continue;
		}
		for (; command[index].opcode; index++)
		{
			if (strcmp(opcode, command[index].opcode) == 0)
			{
				command[index].f(&stack, l_number);
				break;
			}
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

