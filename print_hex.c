#include "main.h"
/**
 * print_hex - Print unsigned integers in hex form.
 * @j: unsigned int
 * @c: flag to determine case of printing,
 *     (0 = lower, 1 = upper).
 * Return: Digits printed.
 */
int print_hex(unsigned int j, unsigned int c)
{
	unsigned int a[8];
	unsigned int i, k, sum;
	char diff;
	int count;

	k = 268435456;
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	a[0] = j / k;
	for (i = 1; i < 8; i++)
	{
		k /= 16;
		a[i] = (j / k) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + diff + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_x - Converts unsigned integer and prints it in lowercase hex notation
 * @x: unsigned integer
 * Return: number of digits
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_X - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
