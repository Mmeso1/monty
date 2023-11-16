#include "monty.h"

/**
 * is_empty_or_command - ...
 * @line: ...
 * Return: ...
 */

int is_empty_or_comment(const char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (!isspace(line[i]) && line[i] != '#')
			return (0);
		i++;
	}

	return (1);
}


/**
 * mapInstructions - map the commands to their respective functions
 * @args: the argument string that contains the
 * instruction e.g push
 *
 * @stack: a variable created from the stack_t struct
 * @line_number: the line number
 * Return: nothing
 */
void mapInstructions(char *args, stack_t **stack, unsigned int line_number)
{

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(args, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args);
	exit(EXIT_FAILURE);
}
