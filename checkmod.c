#include"shell.h"
/**
 * checks_termnl_mode - Function that checks the mode of my terminal
 * 
 * @argc:counts the number of arguments
 * Return: 1 in case it is in interactive mode
 * 0 in case is is non interactive mode
 * and -1 in case of error
*/
int checks_termnl_mode(int argc)
{
	struct stat stdin_stat;

	fstat(STDIN_FILENO, &stdin_stat);
	if (argc == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);
	if ((!isatty(STDIN_FILENO) && argc == 1))
		return (NON_INTERACTIVE_PIPE);
	if ((argc >= 1))
		return (NON_INTERACTIVE_MODE);
	return (ERROR);
}
