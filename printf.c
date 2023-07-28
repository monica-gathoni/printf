#include "main.h"

/**
*specifiers - checks for specifiers
*@format: format spec
*Return: pointer to func
*/
static int(*specifiers(const char *format))(va_list)
{
	unsigned int i;
		print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"d", print_d},
		{"i", print_i},
		{"S", print_S},
		{"r", print_r},
		{NULL, NULL}
	};
	for (i = 0; p[i].t != NULL; i++)
	{
		if (*p[i].t == *format)
		{
			break;
		}
	}
	return (p[i].f);
}
/**
*_printf -prints
*@format: list of arg tpes
*Return: no of char printed
*/
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0;
	va_list op;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(op, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			j++;
		}
		if (!format[i])
			return (j);
		f = specifiers(&format[i + 1]);
		if (f != NULL)
		{
			j += f(op);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		j++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(op);
	return (j);
}
