#include "main.h"
/**
 * print_common_error - Print common part of the error message.
 * @data: A struct containing the program's data.
 * @n_as_string: String representation of a number.
 */
void print_common_error(data_of_program *data, char *n_as_string)
{
	_printe(data->program_name);
	_printe(": ");
	_printe(n_as_string);
	_printe(": ");
	_printe(data->command_name);
}

/**
 * print_specific_error - Print specific details of the error message.
 * @data: A struct containing the program's data.
 * @errorcode: The error code.
 */
void print_specific_error(data_of_program *data, int errorcode)
{
	if (errorcode == 2)
	{
		_printe(": Illegal number: ");
	}
	else if (errorcode == 3)
	{
		_printe(": can't cd to ");
	}
	_printe(data->tokens[1]);
	_printe("\n");
}

/**
 * print_error_message - Print error message based on the error code.
 * @data: A struct containing the program's data.
 * @errorcode: The error code.
 */
void print_error_message(int errorcode, data_of_progrram *data) {
    char n_as_string[10] = {'\0'};

    n_as_string = itoa(data->exec_counter);

    print_common_error(data, n_as_string);
    if (errorcode == 2 || errorcode == 3)
	{
		print_specific_error(data, errorcode);
	}
	else if (errorcode == 127)
	{
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(": Permission denied\n");
	}
}
