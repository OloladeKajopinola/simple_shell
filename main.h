#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void execmd(char **argv);
char *locator(char *command);
void free_argv(char **argv);

#endif /* MAIN_H */
