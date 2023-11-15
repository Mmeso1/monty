#include "monty.h"

/**
 * push - to push items into the stack or queue
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (arg == NULL || _isdigit(arg) == 1)
		handle_error(line_number, "usage: push integer", stack);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		handle_error(0, "Error: malloc failed", stack);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	if (isStack)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		stack_t *temp = *stack;

		while (temp && temp->next)
			temp = temp->next;
		if (!temp)
			*stack = new_node;
		else
		{
			temp->next = new_node;
			new_node->prev = temp;
		}
		new_node->next = NULL;
	}
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

/**
 * pint -  prints the value at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line where the error occurs
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next ==NULL)
	{
		fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
