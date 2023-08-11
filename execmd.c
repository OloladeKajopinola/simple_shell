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
	int pid;

	if (argv)
	{
		command = argv[0];
		actual_command = locator(command);

		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting Myshell.......\n");
	//		free_argv(argv);
                        exit(0);
                }
		if ((pid = fork()) == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			if (actual_command == NULL)
			{
				printf("Command not found: %s\n", command);
			exit(1);
		}
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Eexecve");
			exit(1);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
		}
	}
}
