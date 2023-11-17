#include "main.h"
/**
 * _strcompare - Compare two strings
 * @string1: String 2
 * @string2: String 1
 * @number: The number of characters to be compared, 0 if infinite
 * Return: 1 if equalates ,0 if differs
 */
int _strcompare(char *string1, char *string2, int number)
{
	int counter;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (_strlen(string1) != _strlen(string2))
			return (0);
		for (counter = 0; string1[counter]; counter++)
		{
			if (string1[counter] != string2[counter])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (counter = 0; counter < number ; counter++)
		{
			if (string1[counter] != string2[counter])
			return (0);
		}
		return (1);
	}
}

