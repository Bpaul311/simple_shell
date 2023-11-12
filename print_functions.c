#include "main.h"

/**
*_printf - displays characters to STDOUT
*@str:string to be printed.
*Return: number of display bytes
	*returns -1 on failure 
*/

int _printf(char *str)
{
	return write(STDOUT_FILENO, str, strlen(str));
}
/**
 * _printerr - Display an array of chars to the STDERR
 * @str: A pointer to the array of chars
 * Return: the number of bytes displayed.
 * On error, -1 is returned and errno is set appropriately.
 */
int _print_err(char *str)
{
	return write(STDERR_FILENO, str, strlen(str));
}

void manag_eof(int signal)
{
	print("\n", STDOUT_FILENO);
	print(PROMPT, STDOUT_FILENO);
}
