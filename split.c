#include "main.h"
/**
   * split - Tokenize the string
   * @data: A pointer to program's data
   * Return: An array of the tokens.
   */
void split(ProgramData *data)
{
	char *delim = " \t";
	int i, j, counter = 2, len;

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
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = _str_duplicate(str_tok(data->input_line, delim));
	data->command_name = _str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = _str_duplicate(str_tok(NULL, delim));
	}
}
