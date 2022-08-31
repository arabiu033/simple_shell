#ifndef _SHELL_H_
#define _SHELL_H_

/* Standard library files */
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
extern char **environ;

/**
 * struct linked_path - singly linked list
 * @s: string to break into link list
 * @next: points to the next node
 *
 * Description: links the directories in PATH
 */
typedef struct linked_path
{
	char *s;
	struct linked_path *next;
} lp;

/* Customised fuctions to works with strings */
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* write and read functions created */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_arguments(char *str);
void _puts(char *str);
int _putchar(char c);
char _getc(FILE *stream);
void error_message(int p, char *s);

/* malloc related fucntions */
void free_pointer(char **ptr, int count);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* environment related functions */
void _printenv(void);
char *_getenv(const char *name);
void _path_directories(void);
lp *_path_directories_list(void);

/* path related functions lp */
lp *linked_list(lp **head, const char *str);

#endif /* #define _SHELL_H_ */
