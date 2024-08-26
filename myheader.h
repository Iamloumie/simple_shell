#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX_USER_INPUT 1024
extern char **environ;

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/types.h>

int _strlen(char *str);
int _strlenc(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_stmstr(char *str);
int _strncmp(const char *str1, const char *str2, size_t num);
char *_strdup(const char *str);


void error(char *cmd);
void childpro_exec(char *cmd, char *args[]);
void print_env_var(void);
int cmd_exec(char *cmdargs);
void ch_user_dir(char *filepath);
void builtin_cmd(char *user_input);
void prompt_disp(void);
char *path_finder(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void clear_screen(void);




#endif
