#include "main.h"
/**
 * print_char - Print characters.
 * @ar_list: Store the a list of characters.
 * Return: Num of parameters printed.
 */
int print_char(va_list ar_list)
{
	int c = va_arg(ar_list, int);

	return (_putchar(c));
}

/**
* print_string - Prints string.
* @ar_list: Store the a list of characters.
* Return: Number of parameters printed.
*/
int print_string(va_list ar_list)
{
	int i;
	int count = 0;

	char *str;

	str = va_arg(ar_list, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		count += _putchar(str[i]);

	return (count);
}
