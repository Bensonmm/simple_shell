#include"shell.h"
/**
 * _error_print - Prints an error message to the standard error stream.
 * @name_shell: The name of the shell program.
 * @tally: The command tally.
 * @command_array: The command or argument causing the error.
 * @type_of_error: The type of error.
 * Return: nothing
 */

void _error_print(char *name_shell, int tally,
char *command_array, int type_of_error)
{
	char *tally_string;


	tally_string = characters_to_numbers(tally);

	write(STDERR_FILENO, name_shell, _string_len(name_shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tally_string, _string_len(tally_string));
	write(STDERR_FILENO, ": ", 2);


	if (type_of_error == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, command_array, _string_len(command_array));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (type_of_error == NOT_FOUND)
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if (type_of_error == PERMISSION_DENIED)
	{
		write(STDERR_FILENO, "Permission denied\n", 18);
	}


	free(tally_string);
}
