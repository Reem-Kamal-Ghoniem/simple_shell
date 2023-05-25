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
	char **argv = NULL;
	size_t size = 0;
	char *s = NULL, *t;
	pid_t id;


	id = fork();
	if (id != 0)
	{
		wait(NULL);
		free_argv(argv);
		return;
	}


	if (getline(&s, &size, stdin) == -1)
		exit(0);
	argv = command_line(s);
	exit_status(argv, s);
	if (!(argv[0]) || environment(argv, env) || _cd(av[0], argv, env))
	{
		free_argv(argv);
		return;
	}
	t = _path(argv[0], env);
	if (t)
		argv[0] = t;
	if (execve(argv[0], argv, env) == -1)
		perror(av[0]);

}
/**
 * main - simple shell
 * @ac: number of arguments
 * @av: argument
 * @env: environment
 * Return: 0 on success
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	char **argv = NULL;
	size_t size = 0;
	char *s = NULL, *t;
	int st;
	pid_t id;
	FILE *fd = stdin;

	if (av[1])
	{
		fd = fopen(av[1], "r");
		if (fd == NULL)
		perror(av[0]), exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO) && fd == stdin)
			write(1, "#cisfun$ ", 9);
		if (getline(&s, &size, fd) == -1)
			free(s), exit(0);
		argv = command_line(s), exit_status(argv, s);
		if (!(argv[0]) || environment(argv, env) || _cd(av[0], argv, env))
		{
			free_argv(argv);
			continue;
		} t = _path(argv[0], env);
		if (t)
			argv[0] = t;
		if (access(argv[0], X_OK) == -1)
		{
			perror(av[0]);
			continue;
		} id = fork();
		if (id > 0)
		{
			waitpid(id, &st, 0), free_argv(argv);
			continue;
		}
		if (id == -1 || execve(argv[0], argv, env) == -1)
			perror(av[0]), exit(1);
	} return (0);
}
