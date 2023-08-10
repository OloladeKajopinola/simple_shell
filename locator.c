#include "main.h"

/**
 * locator - Function take command that was passed
 * @command: Character pointer to access environment variable path
 *
 * Return: Path of the command
 */

char *locator(char *command)
{
	/* Variable to store information */
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	/* Get the system's PATH environemnt variables */
	path = getenv("PATH");
	if (path)
	{
		/* make a copy of PATH to work with */
		path_copy = strdup(path);
		command_length = strlen(command);
		/* Tokenize PATH by colon to find directories */
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			/* Create a path to the command file */
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			/** strcat(file_path, "\0");
			 * commentig this line off as it is 
			 * not neccesary
			 */

			/* Check if he file exists at this path */
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				/* Return the path */
				return (file_path);
			}
			else
			{
				free(file_path);
				/* moveto the next directory */
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		/* Check if the command xistsin the current directory */
		if (stat(command, &buffer) == 0)
			/* Return the command name */
		return (command);
		/* Command not found */
		return (NULL);
	}

	/* PATH not found */
	return (NULL);
}
