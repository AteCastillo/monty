#include "monty.h"

void pint_f(stack_t **stack, unsigned int line_number)
{
/* function taken from task 0 of 0x17-doubly_linked_lists project*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
        frees(*stack);
		exit(EXIT_FAILURE);
	}
    printf("%d\n", (*stack)->n);
	return;
}

void pop_f(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
        frees(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
    }
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(current);
	return;

    
}