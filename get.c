#include "main.h"
/*static char *s;*/
int get(char **c, size_t *n, int fd)
{
	int st =1 , i;
	char buffer[1024];

	printf("%s",*c);
	while(st)
	{
		st = read(fd, buffer, 1024);
		if (!st)
			break;
		(*n) = (*n) + st;
/*		temp = (c + j);*/
/*		for(i = 0; i < st; i++)
		{
			temp[j] = buffer[i];
			printf("%c",temp[j]);
				if (temp[j] == '\n')
			
				{
					printf("reem");
					temp = (c + j + 1);
					temp = malloc(1);
					temp[j + 1] = '\0';
					c = temp;
					return (*n);
				}
			j++;
		}*/
		for(i = 0; i < st; i++)
		{
			if (buffer[i] == '\n' && buffer[i + 1])
			{
				buffer[i + 1] = '\0';
				(*c) = buffer;
				printf("%s",*c);
				return (*n);
			}
		}
	/*	(*c) = string_concat((*c), buffer, "");*/
	}
	if (*n == 0)
		return (-1);
	return(*n);
}
