#include "shell.h"
/**
 * piped_characters_tally - counts the number a character appears in a string
 * @strings: the strings 
 * @c:  Character
 * Return: the number of occurrences of @c in @strings
 */
unsigned int piped_characters_tally(char *strings, char c)
{
	unsigned int tally = 0;

	while (*strings != '\0')
	{
		if (*strings == c)
			tally++;
		strings++;
	}
	return (tally + 1);
}
