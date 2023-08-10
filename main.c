#include "main.h"

/**
 * main -
 * @c:
 * @argv:
 * Return - Success (0)
 */

int main(int c, char **argv)
{
	char *prompt = "(Myshell)$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int a;
	int num_tokens = 0;
	char *token;


	/* typcasting the variables */
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
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
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
	}

	free(lineptr);
	free(lineptr_copy);

	return (0);
}
