#include "main.h"
/**
 * print_common_error - Print common part of the error message.
 * @data: A struct containing the program's data.
 * @n_as_string: String representation of a number.
 */
void print_common_error(ProgramData *data, char *n_as_string)
{
	_print_err(data->program_name);
	_print_err(": ");
	_print_err(n_as_string);
	_print_err(": ");
	_print_err(data->command_name);
}

/**
 * print_specific_error - Print specific details of the error message.
 * @data: A struct containing the program's data.
 * @errorcode: The error code.
 */
void print_specific_error(ProgramData *data, int errorcode)
{
	if (errorcode == 2)
	{
		_print_err(": Illegal number: ");
	}
	else if (errorcode == 3)
	{
		_print_err(": can't cd to ");
	}
	_print_err(data->tokens[1]);
	_print_err("\n");
}

/**
 * print_error_message - Print error message based on the error code.
 * @data: A struct containing the program's data.
 * @errorcode: The error code.
 */
void print_error_message(int errorcode, ProgramData *data)
	{
	char n_as_string[10] = {'\0'};

	converter((long) data->exec_counter, n_as_string, 10);
	print_common_error(data, n_as_string);
	if (errorcode == 2 || errorcode == 3)
	{
		print_specific_error(data, errorcode);
	}
	else if (errorcode == 127)
	{
		_print_err(": not found\n");
	}
	else if (errorcode == 126)
	{
		_print_err(": Permission denied\n");
	}
}
