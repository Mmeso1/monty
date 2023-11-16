#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @line_number: the line number
 * @stack: a double pointer to the stack head
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		if (isalpha((*stack)->n))
			printf("%c\n", (*stack)->n);
		else
			handle_error(line_number, "can't pchar, value out of range", stack);
	}
	else
		handle_error(line_number, "can't pchar, stack empty", stack);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	while (current != NULL && isalpha(current->n) && current->n != 0)
	{
		if (isprint(current->n))
			printf("%c", current->n);
		else
		{
			fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	printf("\n");
}
