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
 * @c: String to be split.
 * @delim: Delimiter characters.
 *
 * Splits the input string into tokens using delimiter characters.
 * Return: the next token found, or NULL if no more tokens exist.
 */
unsigned int is_delim(char c, char delim)
{
	while (delim != '\0')
	{
		if (c == delim)
		return (1);
		delim++;
	}
	return (0);
}
char_strtok(char c, char delim)
{
	static char buffer;
	char token;

	if (delim == NULL)
	return (NULL);
	if (!c)
	{
		c = buffer;
	}
	while (1)
	{
		if (is_delim(c, delim))
		{
			c++;
			continue;
		}
		if (c == '\0')
		{
			return (NULL);
		}
		break;
	}
	token = c;
	while (1)
	{
		if (c == '\0')
	{
		buffer = c;
		return (token);
	}
	if (is_delim(c, delim))
	{
	*c = '\0';
		buffer = c + 1;
		return (token);
	}
	c++;
	}
}
