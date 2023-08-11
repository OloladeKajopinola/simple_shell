#include "main.h"

/**
 * execmd - Execute a command
 * @char:
 * @argv:
 *
 * Return: Return 0.
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = locator(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
		/* Check if the command is "exit"*/
		if (strcmp(command, "exit") == 0)
		{
			/* Free allocated memory and exit the shell */
			free_argv(argv);
			printf("Exiting Myshell.......\n");
			exit(0);/* Use the exit function to  exit the program */

		}
	}
}
/**
 * free_argv - Free memory allocated for argv
 * @argv: Array of strings containing the command and its arguments
 */
void free_argv(char **argv)
{
	for (int i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
