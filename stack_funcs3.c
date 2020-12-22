#include "monty.h"

/**
 * sub_f - to substract the last from the second last
 * @stack: from the struct
 * @line_number: from the struct
 **/
void sub_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack)->next == NULL || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * div_f - to divide the last to the second last
 * @stack: from struct
 * @line_number: from the struct to lnow the line
 **/
void div_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack)->next == NULL || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * mul_f - to multiply thw two lasts
 * @stack: from the struct
 * @line_number: from the struct to know the line number
 **/
void mul_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack)->next == NULL || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * mod_f - to obtain the modulus from the division
 * @stack: from the struct
 * @line_number: from the struct
 **/
void mod_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack)->next == NULL || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}
