#include "main.h"

/**
 * int_mode - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if shell is in interactive mode, if not, Return 0
 */
int int_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * check_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim_str: the delimeter string
 * Return: 1 if character is a delimeter, if not, Return 0
 */
int check_delim(char c, char *delim_str)
{
	while (*delim_str)
		if (*delim_str++ == c)
			return (1);
	return (0);
}

/**
 *check_alpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if character is alphabetic, otherwise 0
 */

int check_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *str_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int str_atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
