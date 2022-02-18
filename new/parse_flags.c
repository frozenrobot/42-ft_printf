/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:12:35 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 16:51:13 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_flags_wc1(int *flags, va_list list)
{
	int	temp;

	temp = va_arg(list, int);
	if (temp < 0)
	{
		flags[2] = 1;
		flags[0] = -1;
		temp *= -1;
	}
	flags[3] = temp;
}

void	parse_flags_notwc1(char *format, int *flags, int *i, va_list list)
{
	int	temp;

	while (format[*i] == '-')
	{
		flags[2] = 1;
		(*i)++;
	}
	if (format[*i] == '*')
	{
		temp = va_arg(list, int);
		if (temp < 0)
		{
			temp *= -1;
			flags[2] = 1;
		}
		flags[3] = temp;
		(*i)++;
	}
	else
	{
		flags[3] = ft_atoi(format, *i);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
}

void	parse_flags_dot_elseif(char *format, va_list list, int *flags, int *i)
{
	int	temp;

	(*i)++;
	if (format[*i] == '*')
	{
		temp = va_arg(list, int);
		flags[1] = temp * -1;
		(*i)++;
	}
	else
	{
		while (format[*i] == '-')
			(*i)++;
		flags[1] = -1 * ft_atoi(format, *i);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
}

void	parse_flags_dot(char *format, va_list list, int *flags, int *i)
{
	flags[1] = 0;
	(*i)++;
	if (format[*i] == '*')
	{
		flags[1] = va_arg(list, int);
		(*i)++;
	}
	else
	{
		if (format[*i] == '-')
			parse_flags_dot_elseif(format, list, flags, i);
		else
		{
			flags[1] = ft_atoi(format, *i);
			while (format[*i] >= '0' && format[*i] <= '9')
				(*i)++;
		}		
	}
}

void	parse_flags(int *flags, char *format, int i, va_list list)
{
	while (is_flag(format[i]))
	{
		if (format[i] == '0')
		{
			while (format[i] == '0')
				i++;
			flags[0] = 1;
		}
		if (format[i] == '*')
		{
			parse_flags_wc1(flags, list);
			i++;
		}
		else
			parse_flags_notwc1(format, flags, &i, list);
		if (format[i] == '.')
			parse_flags_dot(format, list, flags, &i);
	}
	if (!is_conversion(format[i]))
		flags[4] = 1;
	if (flags[1] >= 0 && flags[0] != -1)
		flags[0] = -1;
}
