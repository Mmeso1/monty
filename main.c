#include "monty.h"

/**
 * main - entry point of the program
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 1 if success else 0
 */
unsigned int line_number = 0;

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

	return (0);
}
