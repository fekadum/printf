#include "main.h"

/**
 * print_oct - converts an unsigned int to an octal number
 * @o: unsigned int to convert
 *
 * Return: Number of digits
 */

int print_oct(va_list o)
{
	unsigned int a[11];
	unsigned int i, x, y, sum;
	int count;

	x = va_arg(o, unsigned int);
	y = 1073741824;
	a[0] = (x / y);

	for (i = 1; i < 11; i++)
	{
		y /= 8;
		a[i] = ((x / y) % 8);
	}

	for (i = 0, sum = 0, count = 0; i < 11; i++)
	{
		sum += a[i];

		if (sum || i == 10)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
