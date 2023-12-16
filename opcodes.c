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
 * Return - nothing
*/
void failure(unsigned int line_number)
{
   fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
