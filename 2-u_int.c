#include "main.h"

/**
*print_b - handles b conversion specifier
*@b: unsidned in arg
*Return: arg count
*/

int print_b(va_list b)
{
	unsigned int i, j, k, sum;
	unsigned int is[32];
	int count;

	k = va_arg(b, unsigned int);
	j = 2147483648;
	is[0] = k / j;
	for (i = 1; i < 32; i++)
	{
		j /= 2;
		is[i] = (k / j) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += is[i];
		if (sum || i == 31)
		{
			_putchar('0' + is[i]);
			count++;
		}
	}
	return (count);
}
/**
*print_u - handles unsigned decimal specifier
*@u: unsigned decimal
*Return: u count
*/
int print_u(va_list u)
{
	unsigned int us[10];
	unsigned int i, j, k, sum;
	int count;

	k = va_arg(u, unsigned int);
	j = 1000000000;
	us[0] = k / j;
	for (i = 1; i < 10; i++)
	{
		j /= 10;
		us[i] = (k / j) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += us[i];
		if (sum || i == 9)
		{
			_putchar('0' + us[i]);
			count++;
		}
	}
	return (count);
}
/**
*print_o - handles unsigned octal specifier
*@o: unsigned octal
*Return: o count
*/
int print_o(va_list o)
{
	unsigned int os[11];
	unsigned int i, j, k, sum;
	int count;

	k = va_arg(o, unsigned int);
	j = 1073741824;
	os[0] = k / j;
	for (i = 1; i < 11; i++)
	{
		j /= 8;
		os[i] = (k / j) % 8;
	}
	for (i = 0, sum = 0, count = 0; i < 11; i++)
	{
		sum += os[i];
		if (sum || i == 10)
		{
			_putchar('0' + os[i]);
			count++;
		}
	}
	return (count);
}
