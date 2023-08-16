#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * custom_getline - Function to read a line of text from te user
 *
 */
char *custom_getline(void)
{
	/* A special box to store what the user typed */
	static char buffer[BUFFER_SIZE];
	/* A number to remember where we stopped reading */
	static size_t index = 0;
	/* How many bytes is been read */
	static ssize_t bytes_read = 0;
	/* Total letters read = final message */
	char *line = NULL;
	/* length of message */
	size_t line_length = 0;

	while(1)
	{
		/* if the box is empty, put in letters to read*/
		if (index >= bytes_read)
		{
			/* Read letter from the keyboard */
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			/* Cant read anymore... */
			if (bytes_read <= 0)
			{
				if (line_length == 0)
				{
					/* if nothing is typed, stop shell */
					return NULL;
				}
				/* otherwise, stop reading and continue */
				break;
			}
			/* Start reading from the beginning of the letters */
			index = 0;
		}
		/* Look for the enter key or the end of the box */
		while (index < bytes_read && buffer[index] != '\n')
		{
			/* increment or move to next character*/
			index++;
			/* Count letters read */
			line_length++;
		}
		/* Create a space to put the words typed */
		line = realloc(line, line_length + 1);
		if (!line)
		{
			/* error handling for space creation */
			perror("realloc");
			/* stop and exit */
			exit(1);
		}
		/* Copy letters from box to space */
		size_t copy_start = index - line_length;
		strncat(line, buffer + copy_start, line_length);

		/* "Enter" key found, stop and show message */
		if (index < bytes_read && buffer[index] == '\n')
		{
			/* read over the "Enter" */
			index++;
			/*Stop reading letters */
			break;
		}
	}
	/* Nice and complete section */
	if (line)
	{
		line[line_length] = '\0';
	}
	/* Return typed message */
	return line;
}

/* main function */
int main(void)
{
	while(1)
	{
		printf("(Myshell)$ ");
		fflush(stdout);

		/* Use function created to read input from keyboard */
		char *line = custom_getline();
		/* if nothing typed, stop shell */
		if (!line)
		{
			/* show message and break */
			printf("Exiting Myshell.........\n");
			break;
		}
		/* otherwise, show message typed */
		printf("You entered: %s\n", line);
		free(line);
	}
	return 0;
}
