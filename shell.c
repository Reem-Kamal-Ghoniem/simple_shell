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
	exit_status(argv);
	if (!(argv[0]) || environment(argv) || _cd(av[0], argv, env))
		return;;
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
	struct stat file;

	if (!isatty(STDIN_FILENO))
		non_interactive(av, env);
	while (isatty(STDIN_FILENO))
	{
/*		if (av[1])
		{
			fd = open(av[1], O_RDONLY);
			if (fd == -1)
				perror(av[0]), exit(1);
		}
		else*/
		write(1, "#cisfun$ ", 9);
		if (getline(&s, &size, stdin) == -1)
			exit(0);
		argv = command_line(s), exit_status(argv);
		if (!(argv[0]) || environment(argv) || _cd(av[0], argv, env))
			continue;
		t = _path(argv[0], env);
		if (t)
			argv[0] = t;
		if (stat(argv[0], &file) == -1)
		{
			perror(av[0]);
			continue;
		} id = fork();
		if (id > 0)
		{
			waitpid(id, &st, 0);
			continue;
		}
		if (id == -1 || execve(argv[0], argv, env) == -1)
			perror(av[0]), exit(1);
		free_argv(argv);
	} return (0);
}
