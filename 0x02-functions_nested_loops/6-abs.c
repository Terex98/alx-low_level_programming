#include "main.h"

/**
 * _abs - function that computes the absolute
 * value of an integer
 *
 * @n: takes an integer type input for funtion
 *
 * Return: Always 0 (Success)
 */

int _abs(int n)
{
	if (n < 0)
		n = (-1) * n;
	return (n);
}
