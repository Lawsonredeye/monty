#include "monty.h"
/**
 * push - pushes integers into the stack
 * @stack: head node/link
 * @value: number being passed
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = value;
	temp->prev = NULL;
	temp->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = temp;

	*stack = temp;
}

/**
 * pall - prints out content in the stack
 * @stack: head node/link
 * @line_number: void
 * Return: Nothing
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
 * failed_prog - exit if the command passed is more than 2
 * Return - Nothing
 */
void failed_prog(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * pint - prints the value at the top of the
 * stack, followed by a new line.
 * @stack: head node to be used
 * @line_number: current line number from program
 * Return: Nothing (void)
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
