#include "main.h"

/**
 * _strncpy - copy strings
 * @dest: destination string
 * @src: source string
 * @n: number of chars to append to dest
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = '\0';
	while (i < n)
	{
		dest[i] '\0';
		i++;
	}
	return (dest);
}
