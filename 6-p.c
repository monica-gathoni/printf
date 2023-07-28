#include "main.h"

/**
*_pow - calculates an exponent
*@base: exponemt's base
*@exponent: exponent of number
*Return: base raised to exponent
*/
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long answ = base;

	for (i = 1; i < exponent; i++)
	{
		answ *= base;
	}
	return (answ);
}
/**
*print_p - prints an adddress
*@p: pointer arg
*Return: count
*/
int print_p(va_list p)
{
	unsigned int opp[16];
	unsigned int i, sum;
	unsigned long j, k;
	char *c = "(nil)";
	int count = 0;

	k = va_arg(p, unsigned long);
	if (k == 0)
	{
		for (i = 0; c[i]; i++)
		{
			_putchar(c[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	j = _pow(16, 15);
	opp[0] = k / j;
	for (i = 1; i < 16; i++)
	{
		j /= 16;
		opp[i] = (k / j) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += opp[i];
		if (sum || i == 15)
		{
			if (opp[i] < 10)
			{
				_putchar('0' + opp[i]);
			}
			else
				_putchar('0' + ('a' - ':') + opp[i]);
			count++;
		}
	}
	return (count);
}
