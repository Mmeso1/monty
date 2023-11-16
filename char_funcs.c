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
