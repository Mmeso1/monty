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

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(line_number, "can't sub, stack too short", stack);

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(line_number, "can't div, stack too short", stack);

	if ((*stack)->n == 0)
		handle_error(line_number, "division by zero", stack);

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: a double pointer to the stack head
 * @line_number: the line number
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(line_number, "can't mul, stack too short", stack);

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
