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
