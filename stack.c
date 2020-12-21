#include "monty.h"
int token2_atoi = 0;
/**
 * structs - to generate and array of structs
 * @token1: pointer received to the first token of the line
 * @stack: doble pointer from struct
 * @line_number: int to know the number of every line from the struct
 * Return: an int
 */

int structs(char *token1, stack_t **stack, unsigned int line_number)
{
    int i = 0;
    instruction_t op_func[] = {
        {"push", push_f},
        {"pall", pall_f},
        {NULL, NULL}
    };
    if (token1 == NULL)
        return (0);
}
    while (op_func[i].opcode != NULL)
    {
        if (strcmp(token1, op_func[i].opcode) == 0)
        {
            op_func[i].f(stack, line_number);
            return (0);
        }
        i++;
        
    }
    return (1);
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
    add_dnodeint(stack, n);
}

/**
 * atoi_number - to convert a char into atoi
 * @token2: second token of the line
 * @linecheck: int to know the number of line 
 * Return: nothing
 */
void atoi_number(char *token2, unsigned int linecheck)
{
    int token2_atoi = 0;

    if (token2 == NULL || token2 < 48 || token2 > 57)
        printf("L%d: usage: push integer", linecheck);
        exit(EXIT_FAILURE);
    token2_atoi = atoi(token2);
}

/**
 * pall_f - to print the values in the stack
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: nothing
 */

void pall_f(stack_t **stack, unsigned int line_number)
    stack_t *h = NULL;

    (void) line_number;
/* function taken from task 0 of 0x17-doubly_linked_lists project*/
	if (stack == NULL)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h == NULL)
		return (0);
	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return;

/**
 * add_dnodeint - to add node at the beginning
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: int.
 */

void *add_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *tmp = *stack;

    (void) line_number;

	if (newnode == NULL)
    {   
        printf("Error: malloc failed");
		exit(EXIT_FAILURE);

	if (*stack == NULL)
	{
		newnode->n = token2_atoi;
		newnode->prev = NULL;
		newnode->next = NULL;
		*stack = newnode;
		return;
	}

	tmp = *stack;
	newnode->n = token2_atoi;
	newnode->prev = NULL;
	newnode->next = tmp;
	tmp->prev = newnode;
	*stack = newnode;
	return;
}