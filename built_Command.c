#include "main.h"

/**
 * execute_builtin - Execute a built-in command
 * @command: The command to execute
 * @argv: Array of command-line arguments
 *
 * Return: Return 1 or 0 if not buitlincommand
 */
int execute_builtin(char *command, char **argv)
{
	if (strcmp(command, "exit") == 0)
	{
		printf("Exiting Myshell.......\n");
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	return (0);
}
