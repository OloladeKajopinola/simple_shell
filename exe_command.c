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
	int pid, status;

	if (argv)
	{
		command = argv[0];
		actual_command = locator(command);
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(0);
		}
		else if (pid == 0)
		{
			if (execve(actual_command, argv, NULL) == -1)
				if (strcmp(command, "exit") != 0)
				{
					perror("command not found");
				}
			exit(0);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (strcmp(command, "exit") == 0)
			{
				free(argv);
				printf("Exiting Myshell.......\n");
				exit(0);
			}
		}
	}
}
