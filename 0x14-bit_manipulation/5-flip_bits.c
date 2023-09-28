#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @num1: first number
 * @num2: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	int index, count = 0;
	unsigned long int current;
	unsigned long int exclusive = num1 ^ num2;

	for (index = 63; index >= 0; index--)
	{
		current = exclusive >> index;
		if (current & 1)
			count++;
	}

	return (count);
}
