#include "monty.h"
#define TOKEN_DELIMITER " \t\n\r"
int token2_atoi = 0;

/**
 * main - Entry point
 * @argc: to count arguments received
 * @argv: each argument
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	ssize_t get_line;
	char *token1 = NULL, *token2 = NULL, *buffer = NULL;
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
	while ((get_line = getline(&buffer, &len, stream)) != EOF)
	{
		while (buffer[0] == 32 || buffer[0] == 9)
			buffer++;
		if (buffer[0] == '\n' || buffer[0] == '\0')
		{
			linecheck++;
			continue;
		}
		token1 = strtok(buffer, TOKEN_DELIMITER);
		token2 = strtok(NULL, TOKEN_DELIMITER);
		if (strcmp(token1, "push") == 0)
			atoi_number(token2, linecheck);
		/* once token2 exists convert it to int*/
		array_struc(token1, &head, linecheck);
		linecheck++;
	}
	free(buffer);
	frees(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
/**
 * frees - To free the stack
 * @head: pointer to the stack
 * Return: nothing
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
