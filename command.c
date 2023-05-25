#include "main.h"
/**
 * command_line - function that handle the command and its arguments.
 * @s: string of command and arguments
 * Return: array
 */
char **command_line(char *s)
{
	int index = 0, i = 0;
	char **argv;
	char *tok, *tok1;
	int count = 0;

	tok1 = strtok(s, "\n");
	tok = tok1;
	while (tok != NULL)
	{

		count++;
		tok = strtok(NULL, " ");
	}

	argv = malloc(sizeof(char *) * (count + 2));
	tok = strtok(tok1, " ");

	while (tok != NULL)
	{
		if (tok[0] == '#')
		{
			argv[index] = NULL;
			return (argv);
		}
		argv[index] = malloc(stringlen(tok) + 1);
		for (i = 0; i < stringlen(tok); i++)
			argv[index][i] = tok[i];
		argv[index][i] = '\0';
		index++;
		tok = strtok(NULL, " ");
	}
	argv[index] = NULL;
	if (!index)

		return (argv);

/*	free(s);*/
	return (argv);
}
/**
 * free_argv - function to free argv and its elements
 * @argv: array to be freed
 * Return: void
 */
void free_argv(char **argv)
{
	int i;

	if (argv == NULL)
	return;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
