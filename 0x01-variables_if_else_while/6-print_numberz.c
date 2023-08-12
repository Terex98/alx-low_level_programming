#include <stdio.h>
/**
 *main - This is the entry point of the code
 *
 *Return:0 Success
 */
int main(void)
{
	int t;

	for (t = 0; t < 10 ; t++)
		putchar(t + '0');
	putchar('\n');
	return (0);
}
