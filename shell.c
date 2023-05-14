#include "main.h"
#include <string.h>
#include <signal.h>
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
	char *argv[] = {"/bin/ls",NULL};
	long unsigned int size = 0;
	char *s = NULL;
	pid_t id;
	(void)ac;

	if (!isatty(STDIN_FILENO))
		non_interactive(av, env);

	while(isatty(STDIN_FILENO))
	{
		id = fork();
		if (id != 0)
		{
			wait(NULL);
			continue;
		}
		write (1, "#cisfun$ ", 9);
		if (getline(&s, &size, stdin) != -1)
		{
			argv[0] = strtok(strtok(s,"\n")," ");
			if (argv[0] != NULL && execve(argv[0], argv, env) == -1)
			{
				free(s);
				perror(av[0]);
			}
		}
		else
			exit(0);
	

	}
	if(s)
		free(s);
	return (0);
}
