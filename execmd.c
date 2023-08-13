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
			exit(0);
		}
		if ((pid = fork ()) == -1)
		{
			perror("fork");
		}
		else if (strcmp(command, "env") == 0)
		{
			extern char **environ;
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
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
				perror("Execve");
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
