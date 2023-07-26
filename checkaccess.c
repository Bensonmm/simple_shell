#include "shell.h"
/**
  * _checks_access - a function that checks the access
  * for a given command in the command line.
  * @command:  line entered by the user
  * @present: present path turned into linked lists
  *
  * Return: Returns the path of the command
  */

char *_checks_access(char *command, list_paths *present)
{
	char *full_path;
	int found_path, length, command_length, present_path_legnth;

	if (present == NULL)
		return (NULL);
	while (present)
	{
		present_path_legnth = _string_len(present->path);
		command_length = _string_len(command);
		length = (present_path_legnth + command_length + 2);
	
		full_path = (char *)malloc(length * sizeof(char));
	
		_cpy_str(full_path, present->path);
	
		_concat_array(full_path, "/");
	
		_concat_array(full_path, command);

		found_path = 0;
		if (access(full_path, X_OK) == 0)
		{
			found_path = 1;
			break;
		}
		else
			free(full_path);
		
		present = present->next;
	}
	if (found_path)
		return (full_path);

	else
		return (NULL);
}
