#include "main.h"

/**
 * execmd - 
 * @char:
 * @argv:
 *
 * Return: Return 
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
		};
	}
}
