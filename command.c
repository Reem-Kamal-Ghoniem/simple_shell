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

	argv = malloc(sizeof(char *) * (count + 1));
	tok = strtok(tok1, " ");
	while (tok != NULL)
	{
		argv[index] = malloc(stringlen(tok) + 1);
		for(i = 0; i < stringlen(tok); i++)
			argv[index][i] = tok[i];
		index++;
		tok = strtok(NULL, " ");
	}
	argv[index] = NULL;

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
/**
 * stringlen - function that calculate the length
 * @str: the string to be measured
 * Return: length of the string
 */
int stringlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while(str[len] != '\0')
		len++;

	return (len);
}
/**
 * stringcmp - function copare two strings
 * @str1: firsr string
 * @str2: second string
 * Return: int
 */
int stringcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{	
			return (0);
		}
		i++;
	}
	return (1);
}
