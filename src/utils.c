#include "philo.h"

// Recieves two strings and n number of bytes it will compare
// Will return a positive if str1 is bigger than str2 lexicographically
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while ((*str1 || *str2) && n > 0)
	{
		if ((unsigned char)*str1 != (unsigned char)*str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

// Recieves a string and returns the number of chars
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Recieves an int and returns either 1 if it is a number or 0 if not
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

// Recieves a numeric string and converts it to its int
// Skips whitespaces and stops converting when the string is over or a
// non-digit character is found
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == ' '
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && '0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}
