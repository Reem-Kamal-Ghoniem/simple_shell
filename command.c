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
	char *tok, *tok1;
	int count = 0;
	tok1 = strtok(s, "\n");
	tok = strtok(tok1, " ");
	while (tok != NULL)
	{
		count++;
		tok = strtok(NULL, " ");
	}

	argv = malloc(sizeof(char *) * (count + 1));
	tok = strtok(tok1, " ");
	while (tok != NULL)
	{
		argv[index] = malloc(strlen(tok) + 1);
		argv[index] = tok;
		index++;
		tok = strtok(NULL, " ");
	}
	argv[index] = NULL;

	return (argv);
}
