#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

void execmd(char **argv);
char *locator(char *command);
void free_argv(char **argv);

/* These set of functions help execmd to function properly */
int execute_builtin(char *command);
int external_Command(char *actual_command, char **argv);
int mod(int argc, char **argv);

#endif /* MAIN_H */
