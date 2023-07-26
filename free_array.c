#include"shell.h"
/**
 * free_mem_array - Frees memory allocated for an array of strings.
 * @argv: The array of strings to be freed.
 * Return : nothing
 */

void free_mem_array(char **argv)
{
	char **current_character;

	if (argv == NULL)
	{
		return;
	}


	current_character = argv;


	while (*current_character != NULL)
	{

		free(*current_character);

		current_character++;
	}

	/* Free the memory allocated for the array itself */
	free(argv);
}
