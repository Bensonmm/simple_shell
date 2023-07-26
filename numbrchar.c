#include"shell.h"
/**
 * characters_to_numbers - Converts an integer to a string.
 * 
 * @number: The integer to be converted.

 * Return: The string representation of the integer,
 * or NULL on failure.
 */

char *characters_to_numbers(int number)
{
	int tally = 0, temprory = number;
	char *copied_number;

	
	if (number == 0)
		tally = 1;
	else
	{
		while (temprory != 0)
		{
			temprory = temprory / 10;
			tally++;
		}
	}

	copied_number = malloc(sizeof(char) * (tally + 1));
	if (!copied_number)
	{
		perror("malloc error");
		return (NULL);
	}

	copied_number[tally] = '\0';


	while (tally != 0)
	{
		tally--;
		copied_number[tally] = '0' + number % 10;
		number = (number / 10);
	}


	return (copied_number);
}
