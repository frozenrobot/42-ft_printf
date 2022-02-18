/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:14:19 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 16:53:44 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_flags_neg_int(char *str, int fw)
{
	int	zeroes;
	int	i;

	if (str[0] != '-')
	{
		while (ft_strlen(str) < fw)
			str = zero_add_left(str);
	}
	else if (str[0] == '-' && fw > ft_strlen(str))
	{
		str = char_del_left(str);
		zeroes = fw - (ft_strlen(str) + 1);
		i = 0;
		while (i < zeroes)
		{
			str = zero_add_left(str);
			i++;
		}
		str = char_add_left(str, '-');
	}
	return (str);
}

char	*apply_flags_dot_int(char *str, int prec)
{
	int	zeroes;
	int	i;

	if (str[0] != '-')
	{
		while (ft_strlen(str) < prec)
			str = zero_add_left(str);
	}
	else if (str[0] == '-' && prec > (ft_strlen(str) - 1))
	{
		str = char_del_left(str);
		zeroes = prec - ft_strlen(str);
		i = 0;
		while (i < zeroes)
		{
			str = zero_add_left(str);
			i++;
		}
		str = char_add_left(str, '-');
	}
	return (str);
}

char	*apply_flags_sub(char *str, int *flags, char c)
{
	if (flags[0] != -1 && (c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X'))
	{
		str = apply_flags_neg_int(str, flags[3]);
	}
	else if (flags[1] != -1 && (c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X'))
	{
		str = apply_flags_dot_int(str, flags[1]);
	}
	if (flags[2] == -1 && flags[3] > 0)
	{
		while (ft_strlen(str) < flags[3])
			str = space_add_left(str);
	}
	if (flags[2] == 1 && flags[3] > 0)
	{
		while (ft_strlen(str) < flags[3])
			str = space_add_right(str);
	}
	return (str);
}

char	*apply_flags(char *str, int *flags, char conversion)
{
	int		prec;
	char	*empty;
	char	c;

	prec = flags[1];
	c = conversion;
	if (c == 's' && prec < 0)
		prec = ft_strlen(str);
	if (prec != -1 && c == 's')
		str = strtrim(str, prec);
	if (((c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X')
			&& str[0] == '0' && prec == 0) || (flags[5] == 1 && prec < 6))
	{
		empty = malloc(sizeof(char));
		empty[0] = '\0';
		free(str);
		str = empty;
	}
	if (flags[1] < 0)
		flags[1] = 0;
	str = apply_flags_sub(str, flags, c);
	return (str);
}

char	*produce_string(int *flags, char *format, int i, va_list list)
{
	int		j;
	char	*str;
	char	conversion;

	j = i;
	str = malloc(sizeof(char));
	str[0] = '\0';
	conversion = 'n';
	if (flags[4] == 1)
		return (empty_string(str));
	while (format[j] == '0')
		j++;
	while (is_flag(format[j]))
		j++;
	if (is_conversion(format[j]))
	{
		free(str);
		conversion = format[j];
		str = convert_to_string(format, j, list, flags);
	}
	return (apply_flags(str, flags, conversion));
}
