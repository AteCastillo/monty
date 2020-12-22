#include "monty.h"

/**
 * array_struc - array of structs to compare
 * @token1: the first element in the buffer
 * @head: pointer
 * @linecheck: to check the number of the line
 * Return: an int
 **/
int array_struc(char *token1, stack_t **head, unsigned int linecheck)
{
	int i = 0;
	instruction_t op_func[] = {
		{"push", push_f}, {"swap", swap_f}, {"mul", mul_f},
		{"pall", pall_f}, {"add", add_f}, {"mod", mod_f},
		{"pint", pint_f}, {"sub", sub_f},
		{"pop", pop_f}, {"div", div_f},
		{NULL, NULL}
	};
	if (token1 == NULL)
		return (0);
	while (op_func[i].opcode != NULL)
	{
		if (strcmp(token1, op_func[i].opcode) == 0)
		{
			op_func[i].f(head, linecheck);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", linecheck, token1);
	frees(*head);
	exit(EXIT_FAILURE);
}

/**
 * push_f - to push elements to the stack
 * @stack: from struct
 * @line_number: to checl the number of the line
 **/
void push_f(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	add_dnodeint(stack, token2_atoi);
}

/**
 * atoi_number - to convert chars into ints
 * @token2: second element
 * @linecheck: to check the number of the line
 **/

void atoi_number(char *token2, unsigned int linecheck)
{
	unsigned int i;

	if (token2 != NULL)
	{
		for (i = 0; token2[i] != 0; i++)
		{
			if (token2[i] < 48 || token2[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", linecheck);
				exit(EXIT_FAILURE);
			}
			else
			{
				token2_atoi = atoi(token2);
			}
		}
		return;
	}
	else
	{
	fprintf(stderr, "L%d: usage: push integer\n", linecheck);
	exit(EXIT_FAILURE);
	}
}

/**
 * pall_f - to print every element with push
 * @stack: from struct
 * @line_number: to checl the number of the line
 **/
void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void) line_number;
/* function taken from task 0 of 0x17-doubly_linked_lists project*/
	if (stack == NULL)
	{
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * add_dnodeint - to add node at the begginig
 * @stack: from struct
 * @line_number: to checl the number of the line
 * Return: pointer
 **/
void *add_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	/*stack_t *tmp = *stack;*/

	(void) line_number;
	if (stack == NULL)
	{
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	newnode->n = token2_atoi;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
	return (newnode);
}
