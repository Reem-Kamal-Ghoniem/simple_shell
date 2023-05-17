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
	unsigned int i, j;
	char *ret;

	ret = malloc(strlen(path) + strlen(s) + 2);

/*	temp = path;
	i = strlen(path);
	*(path + strlen(path)) = ss[0];
	*(path + i + 1) = '\0';*/
	for(i = 0; i < strlen(path); i++)
		ret[i] = path[i];
	ret[i] = ss[0];

/*	while(*temp)
		temp++;*/
	i++;
	for(j = 0; j < strlen(s); j++)
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
	while(temp)
	{
		ret = string_concat(temp,"/",s);
                i = access(ret, X_OK);
		if (i == 0)
                        return (ret);
                temp = strtok( NULL, ":");
        }
        return (ret);
}
/**
 * _path - get the path variable
 * @s: the command
 * @env: environment
 * Return: the path
 */
char *_path(char *s, char **env)
{
	int i, j, size = 0, found;
	char *temp, *path;

	if (!access(s, X_OK))
		return (NULL);
	temp = "PATH";
	while(env[size])
		size++;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if(!env[i][j] || env[i][j] != temp[j])
			{
				found = 0;
				break;
			}
			found = 1;
		}
		if (found == 1)
			break;
	}
	temp = strtok(env[i],"=");
	temp = strtok(NULL, "=");
	path = path_ch(s, temp);
	return (path);
}
