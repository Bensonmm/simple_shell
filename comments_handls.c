#include "shell.h"
#include <stddef.h>

/**
 * _handles_comments - Removes comments from the input string.
 * @input: The input string.
 */
void _handles_comments(char *input)
{
	int i = 0;
	char present_char;
	int quote = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		present_char = input[i];

		if (present_char == '"')
		{
			quote = !quote;
		}
		if (present_char == '#' && !quote)  
		{
			input[i] = '\0';
			break;
		}

	}

}
