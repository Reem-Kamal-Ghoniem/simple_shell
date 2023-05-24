#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

void non_interactive(char **av, char **env);
char **command_line(char *s);
char *_path(char *s, char **env);
char *string_concat(char *sl, char *s, char *ss);
char *path_ch(char *s, char *path);
void free_argv(char **argv);
int stringlen(char *str);
int stringcmp(char *str1, char *str2);
void exit_status(char **tok);
int environment(char **tok);
char *stringtok(char *str, const char *del);
int _cd(char *name, char **arg, char **env);
extern char **environ;
#endif
