#include "shell.h"
/**
 * get_id_process - Gets the Representation of Shell instance
 * Return: the process ID.
 */

char *get_id_process()
{
	char *ppid_s;
	pid_t pid = getpid();

	
	ppid_s = characters_to_numbers(pid);


	return (ppid_s);
}
