#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(line_number, "can't add, stack too short", stack);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

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
