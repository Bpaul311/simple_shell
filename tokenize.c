#include "main.h"
/**
 * str_tok - Tokenize string on delims.
 * @line: A pointer to _getline array.
 * @delim: Delimiters.
 * Return: A pointer to the tokenized strings.
 */
char *str_tok(char *line, char *delim)
{
	int j;

	if (line == NULL || *line == '\0')
		return (NULL);
	while (*line != '\0')
	{

		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*line == delim[j])
				break;
		}


		if (delim[j] == '\0')
			break;

		line++;
	}

	char *token = line;

	if (*token == '\0')
		return (NULL);

	while (*line != '\0')
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*line == delim[j])
			{
				*line = '\0';
				line++;

				return (token);
			}
		}

		line++;
	}
}
