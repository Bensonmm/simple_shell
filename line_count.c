/**
 * _tallys_line - Counts the number of lines in a given string.
 * @line: The input string.
 * Return: The number of lines in the string.
 */
int _tallys_line(char *line)
{
	int i = 0;

	while (*line != '\0')
	{
		i++;
		line++;
	}
	return (i);
}
