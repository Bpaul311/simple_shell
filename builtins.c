#include "main.h"
/**
 * find_builtin- search for match and execute the associated builtin func.
 * @data: A struct containing the program's data.
 * Return: Returns the return of the function executed if there is a match,
 * otherwise returns -1.
 **/
int find_builtin(ProgramData *data)
{

	int counter;

	builtin_t arr[] = {
	{"exit", custom_exit},
	{"alias", alias_handler},
	{"cd", cd},
	{"env", Display_env},
	{"setenv", builtin_set_env},
	{"unsetenv", unset_env},
	{NULL, NULL}

};

for (counter = 0; arr[counter].func_name != NULL; counter++)
	{
	if (_strcmp(arr[counter].func_name, data->command_name))

		return (arr[counter].function(data));
	}

	return (-1);
}
