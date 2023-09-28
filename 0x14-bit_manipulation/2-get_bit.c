#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @decimal_num: number to search
 * @bit_index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int decimal_num, unsigned int bit_index)
{
	int bit_value;

	if (bit_index > 63)
		return (-1);

	bit_value = (decimal_num >> bit_index) & 1;

	return (bit_value);
}
