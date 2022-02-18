/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:13:40 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 17:59:46 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	reset_flags(int *flags)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		flags[i] = -1;
		i++;
	}
}

char	*unsigned_int_conversions(char *format, int j, va_list list)
{
	unsigned int	i;
	char			k;
	char			*empty;

	if (format[j] == 'c')
	{
		k = va_arg(list, int);
		empty = malloc(sizeof(char));
		empty[0] = '\0';
		if (k == '\0')
			return (charjoin(empty, -7));
		return (charjoin(empty, k));
	}
	else
	{
		i = va_arg(list, unsigned int);
		if (format[j] == 'u')
			return (putnbr(i));
		else if (format[j] == 'x')
			return (convert_base_hex(i));
		else if (format[j] == 'X')
			return (convert_base_hex_cap(i));
		else
			return ("ERROR");
	}
}

char	*convert_to_string(char *format, int j, va_list list, int *flags)
{
	char	*str;

	if (format[j] == 'c' || format[j] == 'u' || format[j] == 'x'
		|| format[j] == 'X')
		return (unsigned_int_conversions(format, j, list));
	else if (format[j] == 'i' || format[j] == 'd')
		return (putnbr(va_arg(list, int)));
	else if (format[j] == 's')
	{
		str = va_arg(list, char *);
		if (str == NULL)
		{
			flags[5] = 1;
			return ("(null)");
		}
		else
			return (str);
	}
	else if (format[j] == '%')
		return (charjoin("", '%'));
	else if (format[j] == 'p')
		return (strjoin("0x", convert_base_hex_long((unsigned long)
					va_arg(list, unsigned long))));
	else
		return ("ERROR");
}
