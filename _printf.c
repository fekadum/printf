#include "main.h"
/**
 * specs_checks - Validates format specifier checker.
 * @format: Format specifier.
 * Return: If valid function - return pointer.
 *         Otherwise NULL.
 */
static int (*specs_checks(const char *format))(va_list)
{
	unsigned int x;
	printf_t p[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"b", print_bin},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},
		{"p", print_p},
		{'\0', NULL}
	};
	for (x = 0; p[x].t != NULL; x++)
	{
		if (*(p[x].t) == *format)
		{
			break;
		}
	}
	return (p[x].f);
}
/**
 * _printf - Prints format.
 * @format: Argument types passed to the function.
 * Return: Prints number of characters.
 */
int _printf(const char *format, ...)
{
	unsigned int x;
	unsigned int count;

	va_list pf;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(pf, format);
	x = 0;
	count = 0;
	while (format[x])
	{
		for (; format[x] != '%' && format[x]; x++)
		{
			_putchar(format[x]);
			count++;
		}
		if (!format[x])
			return (count);
		f = specs_checks(&format[x + 1]);
		if (f != NULL)
		{
			count += f(pf);
			x += 2;
			continue;
		}
		if (!format[x + 1])
			return (-1);
		_putchar(format[x]);
		count++;
		if (format[x + 1] == '%')
			x += 2;
		else
			x++;
	}
	va_end(pf);
	return (count);
}
