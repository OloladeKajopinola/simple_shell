#include "main.h"

/**
 * external_Command - Execute an external command
 * @actual_command: The actual path of the command
 * @argv: Array of command-line arguments
 *
 * Return: Return 0.
 */
int external_Command(char *actual_command, char **argv)
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (actual_command == NULL)
		{
			printf("Command not found: %s\n", argv[0]);
			exit(1);
		}
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Execve");
			exit(1);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
