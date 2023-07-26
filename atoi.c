#include"shell.h"
/**
 * _atoi_str_int - Converts a string argument to an integer.
 * @s: The string to convert, the input by user
 * Return: Returns the converted integer
 */
int _atoi_str_int(char *s)
{
	unsigned int n, i;
	char positive;

	i = 0;
	n = 0;

	/* Iterate through @ chars  string */
	while (s[i] != '\0')
	{
		/* checks chars is a non-digit */
		if (!((s[i] >= '0') && (s[i] <= '9')))
		{
			return (-1);
		}

		/* checks chars is a digit */
		if (((s[i] >= '0') && (s[i] <= '9')))
		{
			n = (n * 10) + (s[i] - '0');
		}
		else if (s[i] == '+')
		{
			positive++;
		}

		i++;
	}

	return (n);
}
