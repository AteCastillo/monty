#include "monty.h"
#define TOKEN_DELIMITER " \t\n\r"
int token2_atoi = 0;
/**
 * main - tokenize and executing all functions
 * @argc: counter of arguments
 * @argv: arguments received from the prompt
 * Return: nothing
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t get_line;
	char *token1 = NULL;
	char *token2 = NULL;
	stack_t *head = NULL;
	unsigned int linecheck = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((get_line = getline(&buffer, &len, stream)) != -1)
	{
		token1 = strtok(buffer, TOKEN_DELIMITER);
		token2 = strtok(NULL, TOKEN_DELIMITER);
		if (strcmp(token1, "push") == 0)
		{
			atoi_number(token2, linecheck);
		} /* once token2 exists convert it to int*/
		if (token1 && token1[0] != '#')
			structs(token1, &head, linecheck); /* after token1, push it */
		linecheck++;
	}
	free(buffer);
	frees(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
/**
 * frees - to free the stack
 * @head: pointer 
 * Return: none
 */
void frees(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head->prev)
	{
		head = head->prev;
	}

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
