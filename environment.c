#include "main.h"
/**
 * print_env - Display the current environment.
 * @data: A struct containing the program's data.
 * Return: nothing
 */
void print_env(data_of_program *data)
{
	int i;

	for (i = 0; data->env[i]; i++)
	{
		_printf(data->env[i]);
		_printf("\n");
	}
}
/**
 * fetch_info- copies args passed
 * @name: the name
 * @data:  A struct containing the program's data.
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */

char *fetch_info(char *name, data_of_program *data)
{
	int i, len;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);
	len = _strlen(name);
	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (_strcmp(name, data->env[i]) &&
		 data->env[i][len] == '=')
		{
			return (data->env[i] + len + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);
}
/**
 * set_env- - overwrite the value of the env variable
 * or create it if does not exist.
 * @name: the name
 * @data:  A struct containing the program's data.
 * @value: New value
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */

char *set_env(char *name, data_of_program *data, int value)
{
        int i, len, key_exists = 0;

        /* validate the arguments */
        if (key == NULL || data->env == NULL ||  value == NULL)
                return (NULL);
        len = _strlen(name);
        for (i = 0; data->env[i]; i++)
        {/* Iterates through the environ and check for coincidence of the vame */
                if (_strcmp(name, data->env[i]) &&
                 data->env[i][len] == '=')
                {
			key_exists = 1;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = _strcat(_str_duplicate(key), "=");
	data->env[i] = _strcat(data->env[i], value);
	if(!key_exists)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}
/**
 * remove_env - Remove key from the env.
 * @key: Key to be removed.
 * @data: A struct containing the program's data.
 * Return: 1 if the key was removed or 0 if the key does not exist;
 */

int env_remove_key(char *key, data_of_program *data)
{
	int i, len;

        /* validate the arguments */
        if (key == NULL || data->env == NULL)
                return (NULL);
        len = _strlen(name);
        for (i = 0; data->env[i]; i++)
        {/* Iterates through the environ and check for coincidence of the vame */
                if (_strcmp(name, data->env[i]) &&
                 data->env[i][len] == '=')
                {
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
