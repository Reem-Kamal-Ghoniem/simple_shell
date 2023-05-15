#include "main.h"
/**
 * command_line - function that handle the command and its arguments.
 * @s: string of command and arguments
 * Return: array
 */
char **command_line(char *s)
{
	int index = 0;
	char **argv;
	char *tok;
	int count;

	tok = strtok(s, " \n");
	while (tok != NULL)
	{
	count++;
	tok = strtok(NULL, " \n");
	}

	argv = malloc(sizeof(char *) * (count + 1));
	tok = strtok(s, " \n");

	while (tok != NULL)
	{
		argv[index] = malloc(strlen(tok) + 1);
		argv[index] = tok;
		index++;
		tok = strtok(s, " \n");
	}
	argv[index] = NULL;

	return (argv);
}
