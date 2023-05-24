#include "main.h"
/**
 * exit_status - function handles exit and its arguments
 * @tok: the entered command
 * Return: void
 */
void exit_status(char **tok)
{
	int status;

	if (tok[0] != NULL && stringcmp(tok[0], "exit"))
	{
		if (tok[1] != NULL)
		{
			status = atoi(tok[1]);
			free_argv(tok);
			_exit(status);
		}
		else
		{
			free_argv(tok);
			_exit(0);
		}
	}
}
/**
 * environment - function that handle env
 * @tok: the written line
 * @env: env source
 * Return: int
 */

int environment(char **tok, char **env)
{

	if (tok[0] != NULL && stringcmp(tok[0], "env"))
	{
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, stringlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return (1);
	}
	return (0);
}
