#include "main.h"
/**
 * _power - Find the exponent to the base.
 * @base: Base of exponent.
 * @exponent: Exponent of number.
 * Return: base ^ exponent
 */
static unsigned long _power(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_p - Prints an address.
 * @p: Address to print.
 * Return: Number of characters to print.
 */
int print_p(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long x, y;
	char *str = "(nil)";

	x = va_arg(p, unsigned long);
	if (x == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;

	y = _power(16, 15);
	a[0] = x / y;
	for (i = 1; i < 16; i++)
	{
		y /= 16;
		a[i] = (x / y) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
