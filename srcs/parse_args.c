/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:57:20 by prynty            #+#    #+#             */
/*   Updated: 2024/07/24 14:44:09 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

const char	*parse_whitespace(const char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

static long	parse_long(const char *str, int sign, int *error)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && (-result) < -2147483648))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		return (0);
	}
	return (result);
}

int	parse_args(const char *str, int *error)
{
	int		sign;
	long	result;

	sign = 1;
	str = parse_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
	{
		*error = 1;
		return (0);
	}
	result = parse_long(str, sign, error);
	if (*error)
		return (0);
	return ((int)(result * sign));
}
