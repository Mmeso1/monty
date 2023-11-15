#include "monty.h"

/**
 * processLine - To process the line in the cmd and pass to funcs
 * @line: The cmdlinei
 * @line_number: the line number
 * Return: Nothing for now
 */
int isStack = 1;
char *arg = NULL;
void processLine(char *line, unsigned int line_number, stack_t **stack)
{
	char *token, *args[2];
	int i;

	if (line[0] == '#')
		return;

	token = strtok(line, " \t\n");

	for (i = 0; i < 2 && token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
	}

	if (i <= 2)
	{
		if (strcmp(args[0], "stack") == 0)
			isStack = 1;
		else if (strcmp(args[0], "queue") == 0)
			isStack = 0;
		else
		{
			arg = args[1];
			mapInstructions(args[0], stack, line_number);
		}
	}
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
