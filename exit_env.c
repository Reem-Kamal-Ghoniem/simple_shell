#include "main.h"
/**
 * exit_status - function handles exit and its arguments
 * @s: the entered command
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
			_exit(status);
		}
		else
			_exit(0);
	}
}
