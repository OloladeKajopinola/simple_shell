#include "main.h"

/**
 * main - check the code
 * @c: number of command-line arguments 
 * @argv: an array of strings representing those arguments
 * Return - Success (0)
 */

/* Function begins */
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

	/* Beginning of Shell's behaviour*/
	while (1)
	{
		printf("%s", prompt);
		/* assign everything from user to nchars_read */
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

		/**this block tokenizes input
		 * and count the number of token
		 * finally allocates memory for argv
		 */
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		/**Loop tokenizer
		 * This loop assigns copy of input line
		 * to argv element and terminates
		 * when token is NULL
		 */
		token = strtok(lineptr_copy, delim);
		for (a = 0; token != NULL; a++)
		{
			argv[a] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[a], token);

			token = strtok(NULL, delim);
		}
		argv[a] = NULL;

		/**This function seems to be responsible
		 * for executing commands
		 * as it calls execmd with argv array as argument
		 */
		execmd(argv);
	}

	/* frees dynamically allocated memory for lineptr and lineptr_copy */
	free(lineptr);
	free(lineptr_copy);

	return (0);
}
