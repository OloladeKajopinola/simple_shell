#include "shell.h"

/**
 * _putchar - Prints a character to standard error
 * @c: Character to be printed
 * Return: An integer
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
