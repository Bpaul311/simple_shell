#include "main.h"
/**
 * num_of_digits-Calculates the number of digits of a number
 * @num: the number we trynna find the length of
 * Return: the length of the number
 */
int num_of_digits(int num)
{
	unsigned int num1;
	int num_of_digits = 1;

	if (num < 0)
	{
		num_of_digits++;
		num1 = num * (-1);
	}
	else
		num1 = num;

	while (num1 > 9)
	{
		num_of_digits++;
		num1 /= 10;
	}
	return (num_of_digits);
}
/**
 *itoa- converts an int to a string
 * @num: the integer
 * Return: the string
 */
char *itoa(int num)
{
	unsigned int num1;
	int len = num_of_digits(num);
	char *str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	*(str + len) = '\0';

	if (num < 0)
	{
		num1 = num * (-1);
		str[0] = '-';
	}
	else
	{
		num1 = num;
	}
	len--;
	do

	{
		*(str + len) = (num1 % 10) + '0';
		num1 = num1 / 10;
		len--;
	}
		while (num1 > 0);
	return (str);
}
/**
 * _atoi - converts string to an int.
 * @str: A pointer to original string.
 * Return: int of string or 0.
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *str && *str <= '9') && *str != '\0')
	{
		if (*str == '-')
			sign *= -1;
		if (*str == '+')
			sign *= +1;
		str++;
	}

	while ('0' <= *str && *str <= '9' && *str != '\0')
	{

		number = (number * 10) + (*str - '0');
		str++;
	}
	return ((int) (number * sign));
}

/**
 * count_occurrences - Count the occurrences of specific characters
 * @str: The input string to search.
 * @ch: The character to count.
 * Return: The number of occurrences of the character in the string.
 */

int count_occurrences(char *str, char *ch)
{
	int i, counter;

	if (str == NULL || ch == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == ch[0])
		{
			counter++;
		}
		i++;
	}

	return (counter);
}
/**
 * converter - This converts number to string.
 * @num: A number to be converted.
 * @string: A buffer to store the number as string.
 * @base: A base to convert the number
 *
 * Return: Nothing.
 */
void converter(long num, char *string, int base)
{
	int i = 0, is_negative = 0;
	long rem = num;
	char letters[] = {"0123456789abcdef"};

	if (base < 2 || base > 36)
	{
		_printf("invalid base");
		_printf("\n");
		return;
	}
	if (num == 0)
		string[i++] = '0';
	if (string[0] == '-')
		is_negative = 1;

	while (rem)
	{
		if (rem < 0)
			string[i++] = letters[-(rem % base)];
		else
			string[i++] = letters[rem % base];
		rem /= base;
	}
	if (is_negative)
		string[i] = '-';

	string[i] = '\0';
	rev_string(string);
}


