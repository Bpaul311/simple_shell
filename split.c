#include <stdlib.h>
#include <string.h>

/**
   * split - Tokenize the string
   * @data: A pointer to program's data
   * Return: An array of the tokens.
   */
void split(data_of_program *data)
{
	char *delim = " \t";
	int i, j, num_of_tokens = 2, len;

	len = _strlen(data->input_line);
	if (len)
	{
		if (data->input_line[len - 1] == '\n')
			data->input_line[len - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (data->input_line[i] == delim[j])
			num_of_tokens++;
		}
	}
}
