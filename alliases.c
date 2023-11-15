#include "main.h"
/**
 * append_string - This appends a string at the end of the buffer.
 * @buffer: The buffer to which the string will be appended.
 * @str_to_add: The string to be appended.
 * Return: The new length of the buffer, or 0 if either of the strings is null.
 */
int append_string(char *buffer, char *str_to_add)
{
	int length, i;

	if (buffer == NULL || str_to_add == NULL)
		return (0);
	while (buffer[length] != '\0')
		length++;
	i = 0;
	while (str_to_add[i] != '\0')
	{
		buffer[length + i] = str_to_add[i];
		i++;
	}
	buffer[length + i] = '\0';
	return (length + i);
}
/**
 * print_alias_info - Print information about aliases.
 * @data: Pointer to the program's data structure.
 * @alias: Name of the alias to print. If NULL, print all aliases.
 *
 * Prints information about aliases in the program's data.
 * If @alias is provided, prints details for that alias.
 * If @alias is NULL, prints information about all aliases.
 *
 * Return: 0 if successful, or specified error code.
 */
int print_alias_info(data_of_program *data, char *alias)
{
	int i, j, alias_len;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_len = _strlen(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (alias == NULL || (_strcmp(data->alias_list[i], alias, alias_len)
				&& data->alias_list[i][alias_len] == '='))
		{
			for (j = 0; data->alias_list[i][j]; j++)
			{
				buffer[j] = data->alias_list[i][j]
				if (data->alias_list[i][j] == '=')
				break;
			}
		buffer[j + 1] = '\0';
		append_string(buffer, "'");
		append_string(buffer, data->alias_list[i] + j + 1);
		append_string(buffer, "'\n");
		_printf(buffer);
		}
		}
	}

	return (0);
}
/**
 * retrieve_alias_value - Retrieve the value of an alias from the alias list.
 * @data: A struct containing program data.
 * @alias: The name of the alias to retrieve.
 *
 * Return: The value of the alias, or NULL if not found.
 */
char *retrieve_alias_value(data_of_program *data, char *alias)
{
	char *value;
	int i, alias_len;

	/* Validate the arguments */
	if (alias == NULL || data->alias_list == NULL)
		return (NULL);

	alias_len = _strlen(alias);

	for (i = 0; data->alias_list[i]; i++)
	{
		/* Iterates through the alias list and checks for the specified alias */
		if (_strcmp(alias, data->alias_list[i], alias_len) &&
			data->alias_list[i][alias_len] == '=')
		{
			/* Returns the value of the alias (part after the '=' sign) when found */
			value = data->alias_list[i] + alias_len + 1;
			return (value);
		}
	}

	/* Returns NULL if the alias is not found in the alias list */
	return (NULL);
}
/**
 * add_alias - Adds an alias to the list of aliases.
 * @alias_name: The name of the alias to be added.
 * @data: A struct containing program data.
 *
 * Return: 0 if successful, 1 otherwise.
 */
int add_alias(char *alias_name, data_of_program *data)
{
	int i, j;
	char alias_buffer[250] = {'\0'}, *alias_value = NULL;

	/* Validate the arguments */
	if (alias_name == NULL || data->alias_list == NULL)
	return (1);

	/* Iterates alias to find = char */
	for (i = 0; alias_name[i]; i++)
	if (alias_name[i] != '=')
	alias_buffer[i] = alias_name[i];
	else
	{
		/* search if the value of the alias is another alias */
		alias_value = retrieve_alias_value(data, alias_name + i + 1);
		break;
	}

	/* Iterates through the alias list and checks for the varname coincidence */
	for (j = 0; data->alias_list[j]; j++)
	if (_strcmp(alias_buffer, data->alias_list[j], i) &&
	data->alias_list[j][i] == '=')
	{
		/* if the alias already exists */
		free(data->alias_list[j]);
		break;
	}

	/* Add the alias */
	if (alias_value)
	{
		/* if the alias value already exists */
		buffer_append(alias_buffer, "=");
		buffer_append(alias_buffer, alias_value);
		data->alias_list[j] = _str_duplicate(alias_buffer);
	}
	else /* if the alias value does not exist */
	data->alias_list[j] = _str_duplicate(alias_name);
	return (0);
}
