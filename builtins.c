<<<<<<< HEAD
#include "main.h"
/**
 * find_builtin- search for match and execute the associated builtin func.
 * @data: A struct containing the program's data.
 * Return: Returns the return of the function executed if there is a match,
 * otherwise returns -1.
 **/
int find_builtin(data_of_program *data)
{

    int counter;

    builtin_t arr[] = {
        {"exit", custom_exit},
        {"alias", alias_handler},
	{"cd", cd},
	{"env", builtin_env},
	{"setenv", builtin_set_env},
	{"unsetenv", builtin_unset_env},
        {NULL, NULL}
    
};

for (counter = 0; arr[counter].func_name != NULL; counter++)
    {
        if (_strcmp(arr[counter].func_name, data->command))
        
            return (arr[counter].function(data));
    }
    
    return (-1);
 }
=======
#include <stdio.h>

/**
 * builtin_exit - Handles the exit built-in command.
 * @data: A pointer to program's data.
 * Return: 0.
 */
int builtin_exit(data_of_program *data)
{
	printf("Exiting...\n");
	return (0);
}

/**
 * builtin_alias - Handles the alias built-in command.
 * @data: A pointer to program's data.
 * Return: 0.
 */
int builtin_alias(data_of_program *data)
{
	printf("Executing alias command...\n");
	return (0);
}

/**
 * builtin_t_list - Executes the appropriate function based on the command.
 * @data: A pointer to program's data.
 * Return: Result of the executed function or -1 if the command is not found.
 */
int builtin_t_list(data_of_program *data)
{
	int counters;
	builtin_t operators[] = {
		{"exit", builtin_exit},
		{"alias", builtin_alias},
		{NULL, NULL}
	}
};

	for (counters = 0; operators[counters].func_name != NULL; counters++)
	{
		if (_strcmp(operators[counters].func_name, data->command))
		{
			return (operators[counters].function(data));
		}
	}
	return (-1);
>>>>>>> 44e6ecef980ac95bba90a15a2401d8698c1680d8
