#include "shell.h"

/**
 * free_argv - Frees an array of dynamically allocated string
 * @argc: Number to be freed
 * @argv: Array of dynamically allocated strings
 * Return: Void
 */

void free_argv(int argc, char *argv[])
{
	int i = 0;

	if (argv)
	{
		for (; i < argc; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
}
