#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_arguments(char *str, int n, int x);

#endif /* #define _SHELL_H_ */
