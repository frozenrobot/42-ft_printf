/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:08:11 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/21 16:22:30 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_size_ahead(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] <= '9' && str[i + j] >= '0')
	{
		j++;
	}
	return (j);
}

int	ten_power(int exp)
{
	if (exp == 0)
		return (1);
	return (10 * ten_power(exp - 1));
}

int	convert_to_int(char *str, int i, int size)
{
	int	result;
	int	j;

	result = 0;
	j = 1;
	while (j <= size)
	{
		result += ((str[i] - '0') * ten_power(size - j));
		i++;
		j++;
	}
	return (result);
}

int	ft_atoi(char *str, int i)
{
	int	multiply;
	int	size;

	if (!str)
		return (0);
	multiply = 1;
	if (str[i] == '-')
	{
		multiply *= -1;
		i++;
	}
	size = check_size_ahead(str, i);
	return (multiply * convert_to_int(str, i, size));
}

int	ft_atoi_positive(char *str, int i)
{
	int	multiply;
	int	size;

	if (!str)
		return (0);
	multiply = 1;
	if (str[i] == '-')
		return (-1);
	size = check_size_ahead(str, i);
	return (multiply * convert_to_int(str, i, size));
}
