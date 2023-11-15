#include "monty.h"

/**
 * handle_error - Displays an error message,
 * cleans up the stack, and exits with EXIT_FAILURE.
 *
 * @line_number: Line number to be included in the error message.
 * @message: Custom error message to be displayed.
 * @stack: Double pointer to the head of the stack.
 */
void handle_error(unsigned int line_number,
		const char *message, stack_t **stack)
{
	if (line_number != 0)
		fprintf(stderr, "L%d: %s\n", line_number, message);
	else
		fprintf(stderr, "%s\n", message);

	cleanup(*stack);
	exit(EXIT_FAILURE);
}

/**
 * cleanup - to free any dynamically allocated
 * memory in the stack
 * @stack: the pointer to the stack head
 * Return: nothing
 */
void cleanup(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
