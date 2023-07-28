#include "main.h"

/**
* print_c - c specifier for char type
* @c: char
* Return: 1
*/
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}
/**
* print_s - prints an array of chars
* @s: char array
* Return: chars printed
*/

int print_s(va_list s)
{
	int j;
	char *str = va_arg(s, char *);

	if (str == NULL)
	{
		str = (NULL);
	}
	for (j = 0; str[j]; j++)
	{
		_putchar(str[j]);
	}
	return (j);
}
/**
*hex_print - prints character ascii values
*@c: char
*Return: c count
*/
static int hex_print(char c)
{
	int count;
	char diff = 'A' - '-';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (d[count] >= 10)
			_putchar('0' + diff + d[count]);
		else
			_putchar('0' + d[count]);
	}
	return (count);
}
/**
*print_S - handles S conversion specifier
*@S: string
*Return: S count
*/
int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *Str = va_arg(S, char *);

	if (Str == NULL)
		Str = "(null)";
	for (i = 0; Str[i]; i++)
	{
		if (Str[i] < 32 || Str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += hex_print(Str[i]);
		}
		else
		{
			_putchar(Str[i]);
			count++;
		}
	}
	return (count);
}
/**
*print_r - prints string in reverse
*@r: string
*Return: r count
*/
int print_r(va_list r)
{
	char *str;
	int i, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
