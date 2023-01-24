#include "main.h"
/**
 * print_unsigned - Prints an unsigned integer.
 * @u: Unsigned integer to convert.
 * Return: Number of digits.
 */
int print_unsigned(va_list u)
{
	unsigned int a[10];
	unsigned int i, x, y, sum;
	int count;

	x = va_arg(u, unsigned int);
	y = 1000000000;
	a[0] = x / y;

	i = 1;

	for (; i < 10; i++)
	{
		y /= 10;
		a[i] = (x / y) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum || i == 9)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
