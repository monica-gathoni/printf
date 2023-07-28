#include "main.h"

/**
 * print_d - handles d conversion specifier
 * @d: decimal
 * Return: number of printed integers
 */
int print_d(va_list d)
{
	int i[10];
	int j, k, l, sum, num;

	l = va_arg(d, int);
	num = 0;
	k = 1000000000;
	i[0] = l / k;

	for (j = 1; j < 10; j++)
	{
		k /= 10;
		i[j] = (l / k) % 10;
	}
	if (l < 0)
	{
		_putchar('-');
		num++;
		for (j = 0; j < 10; j++)
		{
			i[j] *= -1;
		}
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += i[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + i[j]);
			num++;
		}
	}
	return (num);
}

/**
 * print_i - handles i conversion specifier
 * @i: integer
 * Return: number of printed integers
 */
int print_i(va_list i)
{
	int is[10];
	int j, k, l, sum, num;

	l = va_arg(i, int);
	num = 0;
	k = 1000000000;
	is[0] = l / k;
	for (j = 1; j < 10; j++)
	{
		k /= 10;
		is[j] = (l / k) % 10;
	}
	if (l < 0)
	{
		_putchar('-');
		num++;
		for (j = 0; j < 10; j++)
		{
			is[j] *= -1;
		}
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += is[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + is[j]);
			num++;
		}
	}
	return (num);
}
