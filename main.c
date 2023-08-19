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
	int a, num_tokens = 0, i;
	(void)c;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/* Check if line is empty */
		if (nchars_read == 1)
		{
			/* Skip and prompt again */
			continue;
		}
		if (nchars_read == -1)
		{
			printf("Exiting Myshell.......\n");
			free(lineptr);
			return (-1);
		}
		lineptr_copy = malloc(nchars_read);
		if (!lineptr_copy)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = (char **)malloc(sizeof(char *) * num_tokens);
		if (!argv)
		{
			perror("malloc");
			exit(1);
		}
		token = strtok(lineptr_copy, delim);

		for (a = 0; token!= NULL; a++)
		{
			argv[a] = malloc(strlen(token) + 1);
			if (!argv[a])
			{
				perror("malloc");
				exit(1);
			}
			strcpy(argv[a], token);
			token = strtok(NULL, delim);
		}
		argv[a] = NULL;
		execmd(argv);

		for (i = 0; i < a; i++)
		{
			free(argv[i]);
		}

		free(argv);
		free(lineptr_copy);
	}
	free(lineptr);
	return (0);
}
