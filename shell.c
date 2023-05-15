#include "main.h"
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * non_interactive - non_interactive in shell
 * @av: argument
 * @env: environment
 */
void non_interactive(char **av, char **env)
{
	char *argv[] = {"/bin/ls",NULL};
	long unsigned int size = 0;
	char *s = NULL;
	pid_t id;

	id = fork();
	if (id != 0)
	{
		wait(NULL);
		write (1, "#cisfun$ ", 9);
		return;
	}
		

	if (getline(&s, &size, stdin) != -1)
	{
		argv[0] = strtok(strtok(s,"\n")," ");
		if (execve(argv[0], argv, env) == -1)
			perror(av[0]);
		free(s);
	}



}
/**
 * main - simple shell
 * @ac: number of arguments
 * @av: argument
 * @env: environment
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char **argv;
	long unsigned int size = 0;
	char *s = NULL;
	int st;
        pid_t id;
	struct stat file;
	(void) ac;

	if (!isatty(STDIN_FILENO))
		non_interactive(av, env);
	while(isatty(STDIN_FILENO))
	{
		write (1, "#cisfun$ ", 9);
		if (getline(&s, &size, stdin) != -1)
		{
			argv = command_line(s);
			if (!(argv[0]))
				continue;
			if (stat(argv[0], &file) == -1)
			{
				perror(av[0]);
				continue;
			}
		}
		else
			exit(1);
		id = fork();
		if(id == -1)
			exit(1);
		if (id != 0)
		{
			waitpid(id, &st, 0);
			continue;
		}
		if (execve(argv[0], argv, env) == -1)
		{
			free(s);
			perror(av[0]);
		}
	

	}
	if(s)
		free(s);
	return (0);
}
