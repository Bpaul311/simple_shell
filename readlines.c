#include "main.h"
/**
 * split_and_duplicate - Split the line when a logical operator is found and duplicate the strings.
 * @commands_array: An array of commands.
 * @i: Index to be checked.
 * @j: Counter variable for the character index.
 * @operators_array: An array of the logical operators for each previous command.
 * @operator: The logical operator ('&' or '|').
 *
 * Return: Index of the last command.
 */
int split_and_duplicate(char *commands_array[], int i, int j, char operators_array[], char operator)
{
	char *temp = commands_array[i];
	commands_array[i][j] = '\0';
	commands_array[i] = _strdup(commands_array[i]);
	commands_array[i + 1] = _strdup(temp + j + 2);
	i++;
	operators_array[i] = operator;
	free(temp);
	j = 0;

	return i;
}

/**
 * split_logical_operators - Check for and then split && and || operators.
 * @commands_array: An array of commands.
 * @i: Index to be checked.
 * @operators_array: An array of the logical operators for each previous command.
 *
 * Return: Index of the last command.
 */
int split_logical_operators(char *commands_array[], int i, char operators_array[])
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

	return i;
}


