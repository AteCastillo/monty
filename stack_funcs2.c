#include "monty.h"

/**
 * pint_f - to print the first element of the stack
 * @stack: from struct
 * @line_number: from struct to know number of lines
 **/
void pint_f(stack_t **stack, unsigned int line_number)
{
/* function taken from task 0 of 0x17-doubly_linked_lists project*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - to delete the last element of the stack
 * @stack: from the stack
 * @line_number: from struct to know number of lines
 **/
void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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
}
/**
 * swap_f - to swap the first two elements of the stack
 * @stack: from the stack
 * @line_number: from struct to know number of lines
 **/
void swap_f(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}

/**
 * add_f - to add the last two elements of the stack
 * @stack: from the stack
 * @line_number: from struct to know number of lines
 **/

void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}
/**
 * nop_f - does nothing
 * @stack: from struct
 * @line_number: from struct to know number of lines
 **/
void nop_f(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
