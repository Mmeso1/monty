#include "monty.h"

/**
 * main - entry point of the program
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 1 if success else 0
 */
unsigned int line_number = 0;
int isStack = 1;
char *arg = NULL;
int main(int argc, char *argv[])
{
	char line[100];
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		processLine(line, line_number, &stack);
	}

	fclose(file);
	cleanup(stack);

	return (0);
}


/**
 * processLine - To process the line in the cmd and pass to funcs
 * @line: The cmdlinei
 * @line_number: the line number
 * @stack: the stack
 * Return: Nothing for now
 */
void processLine(char *line, unsigned int line_number, stack_t **stack)
{
	char *token, *args[2];
	int i;

	if (is_empty_or_comment(line))
		return;

	token = strtok(line, " \t\n");

	for (i = 0; i < 2 && token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
	}

	if (i >= 1)
	{
		if (strcmp(args[0], "stack") == 0)
			isStack = 1;
		else if (strcmp(args[0], "queue") == 0)
			isStack = 0;
		else if (args[0][0] != '#')
		{
			arg = args[1];
			mapInstructions(args[0], stack, line_number);
		}
		else if (args[0][0] == '#')
			return;
	}
}
