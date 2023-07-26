
#include"shell.h"
/**
 * textured_to_array - converts text to an array of strings
 *
 * @textured: the text to convert
 *
 * Return: a pointer to a char array containing the converted text
 */
char **textured_to_array(char *textured)
{
	char *token, *command;
	char **command_lines;
	int i;
	unsigned int characters_count;

	characters_count = 0;
	command_lines = NULL;
	i = 0;
	characters_count = piped_characters_tally(textured, '\n');
	command_lines = (char **)malloc((characters_count + 1) * sizeof(char *));
	token = strtok(textured, "\n");
	command = _strup_mem(token);
	command_lines[i++] = command;
	while (token != NULL)
	{
		token = _strtok(NULL, "\n");
		if (token != NULL)
		{
			command = _strup_mem(token);
			command_lines[i++] = command;
		}
	}
	free(textured);
	command_lines[i] = NULL;
	return (command_lines);
}
