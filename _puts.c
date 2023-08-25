#include "shell.h"

/**
 * _puts - prints a given string
 * @str: String to be printed
 * Return: Void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
