#include "main.h"
/**
 * get - getline
 * @c: char
 * @n: size-t
 * @fd: flag
 * Return: int
 */
int get(char **c, size_t *n, int fd)
{
	int st = 1, i;
	char buffer[1024];

	printf("%s", *c);
	while (st)
	{
		st = read(fd, buffer, 1024);
		if (!st)
			break;
		(*n) = (*n) + st;

		for (i = 0; i < st; i++)
		{
			if (buffer[i] == '\n' && buffer[i + 1])
			{
				buffer[i + 1] = '\0';
				(*c) = buffer;
				printf("%s", *c);
				return (*n);
			}
		}
	}
	if (*n == 0)
		return (-1);
	return (*n);
}
