#include "main.h"

/**
*print_R - handles rot13
*@R: string
*Return: R count
*/
int print_R(va_list R)
{
	char *c;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	c = va_arg(R, char *);
	if (c == NULL)
		c = "(ahyy)";
	for (i = 0; c[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == c[i])
			{
				_putchar(output[j]);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			_putchar(c[i]);
			count++;
		}
	}
	return (count);
}
