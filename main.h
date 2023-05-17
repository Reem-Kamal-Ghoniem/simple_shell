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
char *string_concat(char *path, char *sl, char *s);
char *path_ch(char *s, char *path);
#endif
