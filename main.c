#include "main.h"

/**
 * main - check the code
 * @c: number of command-line arguments
 * @argv: an array of strings representing those arguments
 * Return: Success (0)
 */

int main(int c, char **argv)
{
	char *prompt = "(Myshell)$ ", *lineptr = NULL, *lineptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int a, num_tokens = 0;
	(void)c;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting Myshell.......\n");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (a = 0; token != NULL; a++)
		{
			argv[a] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[a], token);
			token = strtok(NULL, delim);
		}
		argv[a] = NULL;
		execmd(argv);
		free(argv);
		}
	free(lineptr);
	free(lineptr_copy);
	return (0);
}
