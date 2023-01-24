#include "main.h"

/**
 * print_binary - converts an unsigned into a binary
 * @b: unsigned integer to convert
 *
 * Return: binary form
 */

int print_binary(va_list b)
{
	unsigned int x, y;
	unsigned int i = 0;
	unsigned int sum = 0;
	unsigned int a[32];
	int count = 0;

	x = va_arg(b, unsigned int);
	y = 2147483648;
	a[0] = (x / y);

	for (i = 1; i < 32; i++)
	{
		y /= 2;
		a[i] = (x / y) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
			if (sum || i == 31)
			{
				_putchar('0' + a[i]);
				count++;
			}
	}
	return (count);
}
