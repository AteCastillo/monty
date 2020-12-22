#include "monty.h"

void sub_f(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = *stack;

    if ((*stack)->next == NULL)
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

void div_f(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = *stack;

    if ((*stack)->next == NULL)
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

void mul_f(stack_t **stack, unsigned int line_number)
{
stack_t *aux = *stack;

    if ((*stack)->next == NULL)
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

void mod_f(stack_t **stack, unsigned int line_number)
{
stack_t *aux = *stack;

    if ((*stack)->next == NULL)
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