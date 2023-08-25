#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void zerror(char *prog, int count, char *cmd);
int _putchar(char c);
void _puts(char *str);
extern char **environ;
int exec(char **args, char **argv);
int exit_num;
int ex_exec(char **args, char **argv, char *fullcmd);
char *full_path(char *paths, char *cmd);
void free_argv(int argc, char *argv[]);
char *path(void);
void fix(char *buffer);
int builtin(char **args, char *progname, char *buffer);
char **tokens(char *string);

int external_Command(char *actual_command, char **argv);
int mod(int argc, char **argv);

#endif /* SHELL_H */
