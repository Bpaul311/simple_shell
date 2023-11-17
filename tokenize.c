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
	static char *str;
	char *token;

	if (line != NULL)
		str = line;
	while (*str != '\0')
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
				break;
		}
		if (delim[j] == '\0')
			break;
		str++;
	}
	token = str;
	if (*token == '\0')
		return (NULL);

	while (*str != '\0')
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;

				return (token);
			}
		}

		str++;
	}
	return (token);
}
