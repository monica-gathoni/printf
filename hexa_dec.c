#include "main.h"

/**
*print_hex - prints unsigned int in hexadecimal
*@n: unsigned int
*@c: flag
*Return: n count
*/
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int hex[8];
	unsigned int i, j, sum;
	char dif;
	int count;

	j = 268435456;
	if (c)
		dif = 'A' - ':';
	else
		dif = 'a' - ':';
	hex[0] = n / j;
	for (i = 1; i < 8; i++)
	{
		j /= 16;
		hex[i] = (n / j) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += hex[i];
		if (sum || i == 7)
		{
			if (hex[i] < 10)
				_putchar('0' + hex[i]);
			else
				_putchar('0' + dif + hex[i]);
			 count++;
		}
	}
	return (count);
}
/**
*print_x - handles unsigned hexadecimal x lower caps
*@x: unsigned hexadecimal
*Return: x count
*/
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
*print_X - handles unsigned hexadecimal X in caps
*@X: unsigned hexadecimal
*Return: X count
*/
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
