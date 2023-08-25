#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/**Error printing functions */
void zerror(char *prog, int count, char *cmd);
void _puts(char *str);
int _putchar(char c);
void free_argv(int argc, char *argv[]);

/*Global Variable*/
extern char **environ;
int exit_num;
int exec(char **args, char **argv);
int ex_exec(char **args, char **argv, char *fullcmd);
char *full_path(char *paths, char *cmd);
char *path(void);
void fix(char *buffer);
int builtin(char **args, char *progname, char *buffer);

char **tokens(char *string);

#endif
