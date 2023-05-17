#include "main.h"
/**
 * exit_status - function handles exit and its arguments
 * @s: the entered command
 * Return: void
 */
void exit_status(char *s)
{
	char *tok;
	char *tok1;
	int status;

	tok1 = strtok(s, "\n");
	tok = strtok(tok1, " ");
	if (tok != NULL && strcmp(tok, "exit") == 0)
	{

		tok = strtok(NULL, "\n");
		if (tok != NULL) 
		{
			status = atoi(tok);
			_exit(status);
		}
		else
			_exit(0);
	}
}
