#include "monty.h"

/**
 * push - to push items into the stack or queue
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL)
		handle_error(line_number, "usage: push integer", stack);

	value = atoi(arg);
	if (value == 0 && strcmp(arg, "0") != 0)
		handle_error(line_number, "usage: push integer", stack);

	if (new_node == NULL)
		handle_error(0, "Error: malloc failed", stack);

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - to print all the content of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
