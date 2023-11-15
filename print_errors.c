#include "main.h"
#include <stdio.h>
#include <stdlib.h>


void _print(const char *str)
{
	printf("%s", str);
}

void _print_errors(int error_found, ProgramData *data)
{

	char str[100] = {"\0"};


	if  (error_found == 1)
	{
		printf("Error 1: This can't be executed\n");
	}

	else if (error_found == 2 || error_found == 3)
	{
		_print_err(data->name_of_program);
		_print_err(str);
		_print_err(":");
		_print_err(data->tokens[0]);
		_print_err("\n");
	}
	else if (error_found == 200)
	{
		_print_err(data->name_of_program);
		_print_err(str);
		_print_err(":");
		_print_err(data->command_name);
		_print_err(": no error found\n");

	}
	else if (error_found == 210)
	{
		_print_err(data->name_of_program);
		_print_err(str);
		_print_err(":");
		_print_err(data->command_name);
		_print_err(": no access granted\n");
	}
	else
	{
		printf("No errors found");
	}

}

void extended_to_string(extended num, char *buff, int size)
{
	itoa(num, buff, 10);
}
