#ifndef _SHELL_H_
#define _SHELL_H_

/* Header files */
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
#include <ctype.h>
#include <errno.h>

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
int _strcmp(char *s1, char *s2);
void print_number(int n);
int word_len(char *str);
int count_words(char *str);
char **_arguments(char *str);
int _str_upper(char *str);
int _isupper(int c);
int check_token(char **str);

/* write and read functions created */
char **_arguments(char *str);
void _puts(char *str);
int _putchar(char c);
char _getc(FILE *stream);
void error_message(int p, char *s, char *cmd);
ssize_t _getline(int fd, char **cmd_ptr);
void invalid_file(char *s1, char *s2);

/* malloc related fucntions */
void free_pointer(char **ptr, int count);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_malloc2D(char **array_2D);
void free_array2D(char **array_2D);

/* environment related functions */
char *_getenv(const char *name);
void _path_directories(void);
lp *_path_directories_list(void);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
char *_which(char *str);
char *_pathFinder(lp *name, char *str);
void free_which(lp *head, int sig);
char **add_environment(char *name, char *value);
char **remove_environment(int rmv);

/* path related functions lp */
lp *linked_list(lp **head, const char *str);
void free_list(lp *head);

/* cd related functions */
int _cd(char *path);
int chdir_error(char *path);
void free_cd(char **lwd, char **cwd);
void update_pwd(char *path);

#endif /* #define _SHELL_H_ */
