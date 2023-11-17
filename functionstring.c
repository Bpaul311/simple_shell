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
 * _strcmp- compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 on succ, or the difference
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}
/**
 * rev_string- reverses a string
 * @s: the string
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;
	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
/**
 * _strcat - concatenates 2 strings.
 * @destination: String 1
 * @source: String 2
 *
 * Return: A pointer to the array
 */
char *_strcat(char *destination, const char *source)
{
	size_t i, j;

	i = 0;
	j = 0;
	if (destination == NULL)
		destination = "";
	if (source == NULL)
		source = "";
	while (destination[i] != '\0')

		i++;


	while (source[j] != '\0')
	{
		destination[i] = source[j];
		i++;
		j++;
	}

	destination[i] = '\0';

	return (destination);
}

/**
 * _str_duplicate - Duplicates a string
 * @str: String to be duplicated
 * Return: duplicated string.
 */
char *_str_duplicate(char *str)
{
	char *res;
	int length, i;

	if (str == NULL)
		return (NULL);

	length = _strlen(str) + 1;

	res = malloc(sizeof(char) * length);

	if (res == NULL)
	{
		errno = ENOMEM;
		perror("Can't allocate memmory");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		res[i] = str[i];
	}

	return (res);
}
