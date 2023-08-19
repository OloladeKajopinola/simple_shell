#include "main.h"

/**
 * locator - Function take command that was passed
 * @command: Character pointer to access environment variable path
 *
 * Return: Path of the command
 */

char *locator(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			/* Allocate memory for full path and null-terminator */
			file_path = (char *)malloc(directory_length + command_length + 2);
			if (!file_path)
			{
				perror("malloc");
				exit(1);
			}
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			file_path = (char *)malloc(command_length + 1);
			if (!file_path)
			{
				perror("malloc");
				exit(1);
			}
			strcpy(file_path, command);
			return (file_path);
		}
	}
	return (NULL);
}
