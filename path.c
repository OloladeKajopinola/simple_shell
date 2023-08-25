#include "shell.h"

/**
 * path - Retrieves and duplicates the path
 * Return: A strings of the PATH Variable
 */

char *path(void)
{
	int i;
	char *dup = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
			dup = strdup(environ[i]);
	}
	/*Make sure to free this return value if it's not NULL*/
	return (dup);
}
