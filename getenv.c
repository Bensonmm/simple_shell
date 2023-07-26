#include"shell.h"
/*BETTY OKAY*/
/**
 * _getenv_var - a function to get environment variable
 * @name: name of enviroment variable to get the value of
 * Return: the value of the enviroment varable
*/

char *_getenv_var(const char *name)
{
	int i;
	char *variable_name;
	char *variable_value;
	char *value = NULL;


	for (i = 0; environ[i] != NULL; i++)
	{
		
		variable_name = strtok(environ[i], "=");
	
		variable_value = strtok(NULL, "=");

	
		if (strcmp(variable_name, name) == 0)
		{
		
			value = variable_value;
			break;
		}
	}

	return (value);
}
