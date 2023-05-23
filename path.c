#include "main.h"
/**
 * string_concat - concatenate the path
 * @path: the path
 * @ss: /
 * @s: commant
 * Return: path
 */
char *string_concat(char *path, char *ss, char *s)
{

	unsigned int i = 0, j, k;
	char *ret;

	ret = malloc(strlen(path) + strlen(s) + 2);
	if(!ret)
		return(ret);
	for (i = 0; i < strlen(path); i++)
		ret[i] = path[i];
	for (k = 0; k < strlen(ss); k++)
	{
		ret[i] = ss[k];
		i++;
	}
	for (j = 0; j < strlen(s); j++)
	{
		ret[i + j] = s[j];
	}
	return (ret);

}
/**
 * path_ch - search for the path
 * @s: the command
 * @path: the path variable
 * Return: the path
 */
char *path_ch(char *s, char *path)
{
	char *ret, *temp;
	int i = 1;

	temp = strtok(path, ":");
	while (temp)
	{
		ret = string_concat(temp, "/", s);
		i = access(ret, X_OK);
		if (i == 0)
		{
			return (ret);
		}
		temp = strtok(NULL, ":");
	}
	return (ret);
}
/**
 * _path - get the path variable
 * @s: the command
 * @en: environment
 * Return: the path
 */
char *_path(char *s, char **env)
{
	int i,  j,  size = 0, found;
	char *temp, *path;
	char *en;

	if (!access(s, X_OK))
		return (NULL);
	temp = "PATH";
	while (env[size])
		size++;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (!env[i][j] || env[i][j] != temp[j])
			{
				found = 0;
				break;
			} found = 1;
		}
		if (found == 1)
			break;
	}
	if(!found)
		return(NULL);
	en = malloc(strlen(env[i]));
	if(!en)
		return (NULL);
	strcpy(en, env[i]);
	temp = strtok(en, "="), temp = strtok(NULL, "=");
	if(!temp)
		return (NULL);
	path = path_ch(s, temp);
/*	free(en);*/
	return (path);
}
