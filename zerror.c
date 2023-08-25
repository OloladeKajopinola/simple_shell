#include "shell.h"

/**
 * zerror - Prints custom erro message to standard error
 * @prog: Program name
 * @count: Command count
 * @cmd: Command entered by user
 * Return: Void
 *
 */

void zerror(char *prog, int count, char *cmd)
{
	_puts(prog);
	_puts(": ");
	_putchar(count);
	_puts(": ");
	_puts(cmd);
	_puts(": not found\n");
}
