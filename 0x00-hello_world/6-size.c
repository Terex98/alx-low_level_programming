#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: usung sizeof to print the size of various types
 *
 * Return: Always 0 (Success)
 *
 */
int main(void)
{
	prinf("size of a char: %lu byte(s)\n", sizeof(char));
	prinf("size of an int: %lu byte(s)\n", sizeof(int));
	prinf("size of a long int %lu byte(s)\n:", sizeof(long int));
	prinf("size of a long long int %lu byte(s)\n:", sizeof(long long int));
	prinf("size of a float %lu byte(s)\n:", sizeof(float));
	return (0);
}
