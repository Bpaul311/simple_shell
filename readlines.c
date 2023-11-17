#include "main.h"

/**
 * split_and_duplicate - Split and duplicate a line when operator is found
 * @commands_array: An array of commands.
 * @i: Index to be checked.
 * @j: Counter variable for character index.
 * @operators_array: An array of the logical operators
 * for each previous command.
 * @operator: The logical operator ('&' or '|').
 *
 * Return: Index of the last command.
 */

int split_and_duplicate(char *commands_array[],
		int i, int j, char operators_array[], char operator)
{
	char *temp = commands_array[i];

	commands_array[i][j] = '\0';
	commands_array[i] = _str_duplicate(commands_array[i]);
	commands_array[i + 1] = _str_duplicate(temp + j + 2);
	i++;
	operators_array[i] = operator;
	free(temp);
	j = 0;

	return (i);
}

/**
 * split_logical_operators - Check for and then split && and || operators.
 * @commands_array: An array of commands.
 * @i: Index to be checked.
 * @operators_array: An array of the logical operators
 * for each previous command.
 *
 * Return: Index of the last command.
 */

int split_logical_operators(char *commands_array[], int i,
		char operators_array[])
{
	int j;

	/* Checks for the & and | in the command line */
	for (j = 0; commands_array[i] != NULL && commands_array[i][j]; j++)
	{
		if (commands_array[i][j] == '&' && commands_array[i][j + 1] == '&')
		{
			i = split_and_duplicate(commands_array, i, j, operators_array, '&');
		}
		else if (commands_array[i][j] == '|' && commands_array[i][j + 1] == '|')
		{
			i = split_and_duplicate(commands_array, i, j, operators_array, '|');
		}
	}

	return (i);
}

/**
* read_line - Take one line from the input prompt.
* @data: program's data struct
*
* Return: read count bytes.
*/
int read_line(ProgramData *data)
{
	char buff[BUFFERSIZE] = {'\0'};
	static char *commands_array[50] = {NULL};
	static char operators_array[50] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!commands_array[0] || (operators_array[0] == '&' && errno != 0) ||
		(operators_array[0] == '|' && errno == 0))
	{
		for (i = 0; commands_array[i]; i++)
		{
			free(commands_array[i]);
			commands_array[i] = NULL;
		}
		bytes_read = read(data->file_descriptor, &buff, BUFFERSIZE - 1);
		if (bytes_read == 0)
			return (-1);
		i = 0;
		do {
			commands_array[i] = _str_duplicate(str_tok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = split_logical_operators(commands_array, i, operators_array);
		} while (commands_array[i++]);
	}

	/*obtains the next command (command 0) and remove it from the array*/
	data->input_line = commands_array[0];
	for (i = 0; commands_array[i]; i++)
	{
		commands_array[i] = commands_array[i + 1];
		operators_array[i] = operators_array[i + 1];
	}

	return (_strlen(data->input_line));
}

