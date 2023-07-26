
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
* _setenv_custom - Set environment variable
* @value: The value to be assigned to the environment variable
* @key: The name of the environment variable
*
* @present: Pointer to the list_paths structure
* This function sets the value of an environment variable.
*/

void _setenv_custom(char *key, char *value, list_paths *present)
{
	int count = 0;
	char *full_env = NULL;

	if (key == NULL || value == NULL)
	{
		return;
	}
	if (present == NULL)
	{
		return;
	}
	count = _string_len(key) + _string_len(value) + 2;
	full_env = malloc(count);
	if (full_env == NULL)
	{
		return;
	}
	_cpy_str(full_env, key);
	_concat_array(full_env, "=");
	_concat_array(full_env, value);
	full_env[count - 1] = '\0';
	free(full_env);

}
