#include "main.h"
/**
 * stringtok - function that splits a string
 * @str: the string to be splited
 * @del: the point to split from
 * Returns: string
 */
char *stringtok(char *str, const char *del)
{
	static char *token = NULL;
	char *start;
	char *end;



	if (str != NULL)
		start = str;
	else
		return (NULL);

	end = strpbrk(start, del);

	if (end != NULL)
	{
		*end = '\0';
		token = end + 1;
	}
	else
		token = NULL;

	token = token;
	return start;
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
	while (str[len] != '\0')
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
