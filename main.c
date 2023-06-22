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
	int i, validop;
	char *l = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	size_t line_len = 0;
	unsigned int line_n = 1;
	instruction_t command[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub},  {NULL, NULL}
	};

	check(ac, av, file);
	while (_getline(&l, &line_len, file) != -1 && !feof(file))
	{
		opcode = strtok(l, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		validop = 0;
		for (i = 0; command[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, command[i].opcode) == 0)
			{
				validop = 1;
				command[i].f(&stack, line_n);
				break;
			}
		}
		if (!validop)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
			free_s(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		} line_n++;
	}
	free(l);
	free_s(stack);
	fclose(file);
	return (0);
}

