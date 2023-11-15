#include "main.h"
/**
 * custom_exit- exits the shell
 * @data: the data structure
 * Return: 0 on success
 */
int custom_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1])
	{
	i = 0;
	while (data->tokens[1][i])
		{
		if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9') && data->tokens[1][i] != '+')
		{
			err_num = 2;
			return (2);
		}
		i++;
		}
		err_num = _atoi(data->tokens[1]);
	}

	free_everything(data);
	exit(errno);
}
/**
 * unset_env - Removes the environmnent.
 * @data: A struct containing the program's data.
 * Return: 0 on success and another number if it doesnot
 */
int unset_env(data_of_program *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}

/**
 * builtin_set_env - set the environment.
 * @data: The struct for the program's data
 * Return: Zero if success, or another number if specified in the arguments
 */
int builtin_set_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	set_env(data->tokens[1], data->tokens[2], data);

	return (0);
}
/**
 * Display_env - Displays the environment in which the shell is running.
 * @data: A structure containing program data.
 * Return: Zero on success, or a non-zero value if specified in the arguments.
 */
int Display_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_cpy = NULL;

	if (!(data->tokens[1]))
		print_env(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				var_cpy = _str_duplicate(fetch_info(cpname, data));
				if (var_cpy != NULL)
					env_set_key(cpname, data->tokens[1] + i + 1, data);
				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{/* print the variable if it does not exist in the environ */
					_printf(data->tokens[1]);
					_printf("\n");
				}
				else
				{/* returns the old value of the var*/
					set_env(cpname, var_cpy, data);
					free(var_cpy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}
