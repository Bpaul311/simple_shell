#include "main.h"
/**
 * str_tok - Tokenize string on delims.
 * @line: A pointer to _getline array.
 * @delim: Delimiters.
 *
 * Return: A pointer to the tokenized strings.
 */
char *str_tok(char *line, char *delim)
{
	int j;

	/* Check if the line is empty or null */
	if (line == NULL || *line == '\0')
		return NULL;

	/* Iterate over the characters in the line */
	while (*line != '\0')
	{
		/* Check each character against delimiters */
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*line == delim[j])
				break;
		}

		/* If no match is found, break out of the loop */
		if (delim[j] == '\0')
			break;

		/* Move to the next character in the line */
		line++;
	}

	/* Set the token pointer to the current position of line */
	char *token = line;

	/* Check if the token is empty */
	if (*token == '\0')
		return NULL;

	/* Iterate over the remaining characters in the line */
	while (*line != '\0')
	{
		/* Check each character against delimiters */
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*line == delim[j])
			{
				/* Replace the delimiter with null terminator */
				*line = '\0';
				/* Move line to the next character after the delimiter */
				line++;
				/* Return the token */
				return token;
			}
		}

		/* Move to the next character in the line */
		line++;
	}

	/* Return the last token */
	return token;
}
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

	data->tokens = malloc( sizeof(char *) * num_of_tokens);
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(err_num);
	}
	i = 0;
	data->tokens[i] = _str_duplicate(str_tok(data->input_line, delim));
	data->command_name = _str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = _str_duplicate(str_tok(NULL, delim));
	}
}
