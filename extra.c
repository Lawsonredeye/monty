#include "monty.h"

/**
 * sub - subtract the top two elements of the stack.
 * @stack: main stack
 * @line_number: line it was encountered
 * Return - nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;
	int value = 0, value2 = 0;

	if (*stack == NULL)
	{
		free_all(&(*stack));
		failure(line_number);
	}
	/* check if the stack is not less than 2 nodes*/
	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		temp2 = malloc(sizeof(stack_t));
		if (temp2 == NULL)
		{
			free_all(&(*stack));
			malloc_failed();
		}
		/* manually move through the head node to sub the element*/
			value = temp->n;
			pop(&(*stack), line_number);
			temp = *stack;
            value2 = temp->n;
            pop(&(*stack), line_number);
			temp = *stack;
            value2 -= value;
		
		temp2->n = value2;
		temp2->prev = NULL;
		temp2->next = *stack;
		*stack = temp2;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(&(*stack));
		exit(EXIT_FAILURE);
	}
}