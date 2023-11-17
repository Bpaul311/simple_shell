#include "main.h"
/**
 * free_pointers_array - Frees an array of pointers and the array itself.
 * @pointers_array: An array of pointers.
 *
 * Return: Nothing.
 */
void free_pointers_array(char **pointers_array)
{
	int counter = 0;

	if (pointers_array != NULL)
	{
		while (pointers_array[counter] != NULL)
		{
			free(pointers_array[counter]);
			counter++;
		}

		free(pointers_array);
		pointers_array = NULL;
	}
}
/**
 * free_tokens_and_input - Frees the fields in the program's data struct.
 * @data: A struct of program's data.
 *
 * Return: Nothing.
 */
void free_tokens_and_input(ProgramData *data)
{
	if (data->tokens)
		free_pointers_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}
/**
 * free_everything - Frees all data fields.
 * @data: A struct of program's data.
 *
 * Return: Nothing.
 */
void free_everything(ProgramData *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			_print_err(data->program_name);
	}
	free_tokens_and_input(data);
	free_pointers_array(data->env);
	free_pointers_array(data->alias_list);
}

