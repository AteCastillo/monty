#include "monty.h"

/**
 * structs - to generate an array of structs
 * @token1: pointer received to the first token of the line
 * @stack: doble pointer from struct
 * @linecheck: int to know the number of every line
 * Return: none
 */

int structs(char *token1, stack_t **head, unsigned int linecheck)
{
	int i = 0;
	instruction_t op_func[] = {
		{"push", push_f},
		{"pall", pall_f},
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
 * push_f - to push the lines contained in a file
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: nothing
 */

void push_f(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	add_dnodeint(stack, token2_atoi);
}

/**
 * atoi_number - to convert a char into atoi
 * @token2: second token of the line
 * @linecheck: int to know the number of line
 * Return: nothing
 */
void atoi_number(char *token2, unsigned int linecheck)
{
	unsigned int i;

	if (token2 != NULL)
		for (i = 0; token2[i] != 0; i++)
			if (token2[i] < 48 || token2[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer", linecheck);
				exit(EXIT_FAILURE);
			}
			else
			{
				token2_atoi = atoi(token2);
				return;
			}
	else
	{
		fprintf(stderr, "L%d: usage: push integer", linecheck);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_f - to print the values in the stack
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: nothing
 */

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
	return;
}

/**
 * add_dnodeint - to add node at the beginning
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: int.
 */

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
