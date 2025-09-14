#include "miniRT.h"
#include "parsing.h"

int	count_token_nbr(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

static float get_decimal(char   *str, double number)
{
	float	decimal;
	float	fraction;

    str++;  //skip '.'
	decimal = 1.0;
	fraction = 0.0;
    while (*str && ft_isdigit(*str))
	{
		fraction = fraction * 10 + (*str - '0');
		decimal *= 10.0;
        str++;
	}
    number += fraction / decimal;
    return (number);
}

float	ft_atoi_float(char *str)
{
	float	sign;
	float	number;

	sign = 1.0;
	number = 0.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1.0;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
    if (*str == '.')
    {
        number = get_decimal((char *)str, number);
    }
    //float max? is it needed
	return (number * sign);
}