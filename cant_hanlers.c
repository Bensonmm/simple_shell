#include "shell.h"

/**
* cant_open_handler_erros - It handles errors that appears when a certain file cannot open
* @file_name: the name of the file(that cannot be opened)
* @program_name: the program to open the file or attempting to open file
* @tally: a tally variable to keep track.
* Return : void.
*/
void cant_open_handler_erros(char *program_name, int tally, char *file_name)
{

	char *tally_s;

	tally_s = characters_to_numbers(tally);
	write(STDERR_FILENO, program_name, _string_len(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tally_s, _string_len(tally_s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Can't open ", 11);
	write(STDERR_FILENO, file_name, _string_len(file_name));
	write(STDERR_FILENO, "\n", 1);
}
