#include "main.h"
/**
 * _cd - change working directory
 * @name: name of the file
 * @arg: command
 * @env: environment
 * Return: 1 on success
 */
int _cd(char *name, char **arg, char **env)
{
/**	size_t size = 0;
	char *s = NULL;*/
	(void)env;

	if (strcmp(arg[0], "cd"))
		return (0);


	if (arg[1])
	{
		if (arg[1][0] == '-')
		{
			if (chdir(getenv("OLDPWD")))
				perror(name);
		}
		else
			if (chdir(arg[1]))
				perror(name);
	}
	else
		if (chdir(getenv("HOME")))
			perror(name);

/**	setenv("PWD", getcwd(&s, &size);*/
	return (1);
}
