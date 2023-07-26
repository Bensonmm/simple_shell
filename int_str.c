#include"shell.h"
/**
 * _intenger_to_strs - Converts an integer to a string.
 * @n: The integer to convert.
 * @str: The buffer to store the resulting string.
 * Return : nothing
 */
void _intenger_to_strs(int n, char *str)
{
	int tmp;
	int i = 0;

	if (n == 0)
	{
		str[i++] = '0';
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	tmp = n;
	while (i > 0)
	{
		str[--i] = tmp % 10 + '0'; 
		tmp /= 10; 

	}
	str[i] = '\0'; 

}


