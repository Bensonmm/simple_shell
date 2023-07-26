/**
 * _chars_tally - Counts the the times a specific character occur in a strings.
 * @character: The character to count.
 * @strings: The input strings.
 * Return: The number a character appears in a strings
 */
unsigned int _chars_tally(char *strings, char character)
{
	unsigned int tally = 0;

	while (*strings != '\0')
	{
		if (*strings != character && *(strings + 1) == character)
			tally++;
		strings++;
	}
	return (tally + 1);
}
