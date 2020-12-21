#include "monty.h"
#define TOKEN_DELIMITER " \t\n\r"
int token_atoi = 0;

/**
 * main - tokenize and executing all functions
 * @argc: counter of arguments
 * @argv: arguments received from the prompt
 * Return: nothing
 */
int main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
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
       fprintf(stderr, "Error: Can't open file %s\n",argv[1]);
       exit(EXIT_FAILURE);
    }
        
    while ((nread = getline(&line, &len, stream)) != -1) 
    {
        token1 = strtok(line, TOKEN_DELIMITER);
        token2 = strtok(NULL, TOKEN_DELIMITER);
        atoi_number(token2, linecheck); /* once token2 exists convert it to int*/
        structs(token1, &head, linecheck); /* after token1, push it */

        linecheck++;
    }

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}
