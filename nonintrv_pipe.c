#include"shell.h"
/**
 * non_interactive_pipes_handlers - Processes Shell Commands with Pipes
 * Return: pointer to char array with output
 */
char **non_interactive_pipes_handlers()
{
	char c[2048], *textured, **command_lines;
	size_t total_characters_read = 0;
	ssize_t bytes_read;
	int i, flags;

	flags = 0;
	command_lines = NULL;
	textured = NULL;
	while ((bytes_read = read(STDIN_FILENO, c, 2048)) > 0)
	{
		total_characters_read = total_characters_read + bytes_read;
	}
	if (bytes_read == -1)
	{
		perror("reading error");
		exit(ERROR);
	}
	if (total_characters_read > 2048)
		c[2048 - 1] = '\0';
	else
		c[total_characters_read - 1] = '\0';

	for (i = 0; c[i]; i++)
	{
		if (c[i] != ' ')
			flags = 1;
	}
	if (flags == 0)
		return (NULL);
	total_characters_read = _string_len(c);
	textured = (char *)malloc(sizeof(char) * (total_characters_read + 1));
	if (textured != NULL)
	{
		_cpy_str(textured, c);
		textured[total_characters_read] = '\0';
		command_lines = textured_to_array(textured);
	}
	return (command_lines);
}
