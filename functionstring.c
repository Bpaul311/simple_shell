#include "main.h"
/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate
 * Return: the length of @s
 */
int _strlen(const char *s)
{
	int size = 0;

	if (s == NULL)
		return (0);
	while (*s != '\0') /* loops until end of the string */
	{
		size++;
		s++; /* increment s, move up a char in the string */
	}

	return (size);
}
/**
 * _strtok - Split a string into tokens.
 * @str: String to be split.
 * @delim: Delimiter characters.
 *
 * Splits the input string into tokens using delimiter characters.
 * Return: the next token found, or NULL if no more tokens exist.
 */
char *_strtok(char *str, char *delim)
{
	char *token;
	static char *buffer;
	int len = _strlen(delim);
	int i = 0;

	if (delim == NULL)
		return (NULL);

	if (str != NULL)
	{
		buffer = str;
	}
	else if (buffer == NULL || *buffer == '\0')
	{
		return (NULL);
	}

	token = buffer;
	while (*buffer != '\0' && i != len)
	{
		i = 0;
		while (*buffer != '\0' && *buffer != delim)
			buffer++;
		while (buffer[i] == delim[i] && i < len)
			i++;

		if (i == len)
		{
			*buffer = '\0';
			buffer += len;
		}
		else
			buffer++;
	}
	return (token);
}
