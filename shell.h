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
#include <stddef.h>
#include <signal.h>

#define SIGQUIT 3   /* Quit the process */

char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_arguments(char *str);
void free_pointer(char **ptr, int count);
void _puts(char *str);
int _putchar(char c);
int _strcomp(char *s1, char *s2);
int _strlen(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strchr(char *s, char c);

#endif /* #define _SHELL_H_ */
