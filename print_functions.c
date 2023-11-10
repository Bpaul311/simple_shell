#include "main.h"

/**
*print - displays characters to STDOUT
*@str: pointer to characters
*Return: number of display bytes
	*returns -1 on failure 
*/

int print(char *str)
{
	return write(STDOUT_FILENO, str, strlen(str));
}

int print_err(char *str)
{
	return write(STDERR_FILENO, str, strlen(str));
}

void manag_eof(int signal)
{
	print("\n", STDOUT_FILENO);
	print(PROMPT, STDOUT_FILENO);
}
