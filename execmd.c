#include "main.h"

/**
 * execmd - Execute a command
 * @argv: Array of command-line arguments
 *
 * Return: Return 0.
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	int pid;

	if (argv)
	{
		command = argv[0];
		actual_command = locator(command);

		if (execute_builtin(command, argv))
		{
			exit(0);
		}
		external_Command(actual_command, argv);
	}
}
