#include "monty.h"

/**
 * pop - deletes the top of the stack
 * @stack: main stack
 * @line_number: line it was encountered
 * Return - nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		failure(line_number);
	temp = *stack;
	*stack = (*stack)->next;
	/* check again if the stack is empty to assign prev to NULL*/
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * failure - prints the line error and terminates program
 * @line_number: to indicate the current line of the problem
 * Return - nothing
 */
void failure(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * malloc_failed - exits when malloc fails
 * Return: nothing
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * add - adds the top two elements of the stack.
 * @stack: main stack
 * @line_number: line it was encountered
 * Return - nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;
	int i, value = 0;

	if (*stack == NULL)
		failure(line_number);
	/* check if the stack is not less than 2 nodes*/
	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		temp2 = malloc(sizeof(stack_t));
		if (temp2 == NULL)
			malloc_failed();
		/* traverse through the head node to add the element*/
		for (i = 0; i < 2; i++)
		{
			value += temp->n;
			pop(&(*stack), line_number);
			temp = *stack;
		}
		temp2->n = value;
		temp2->prev = NULL;
		temp2->next = *stack;
		*stack = temp2;
	}
}
