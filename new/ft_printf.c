/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:18:46 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 17:59:36 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_retif1(char *format_copy, int *flags, va_list list, int *i)
{
	(*i)++;
	reset_flags(flags);
	parse_flags(flags, format_copy, *i, list);
}

char	*get_retif2(char *format_copy, int len_before, char *ret, int *i)
{
	if (len_before == ft_strlen(ret) && format_copy[*i] == '%'
		&& format_copy[*i - 1] == '%')
	{
		ret = charjoin(ret, '%');
		(*i)++;
	}
	else
	{
		while (is_flag(format_copy[*i])
			|| (format_copy[*i] >= '0' && format_copy[*i] <= '9'))
			(*i)++;
		(*i)++;
	}
	return (ret);
}

char	*get_ret(char *format_copy, va_list list, char *ret, int *flags)
{
	int	i;
	int	len_before;

	i = 0;
	while (format_copy[i] != '\0')
	{
		while (format_copy[i] != '%' && format_copy[i] != '\0')
		{
			ret = charjoin(ret, format_copy[i]);
			i++;
		}
		if (format_copy[i] == '%')
		{
			get_retif1(format_copy, flags, list, &i);
			len_before = ft_strlen(ret);
			ret = strjoin_frees1(ret,
					produce_string(flags, format_copy, i, list));
			ret = get_retif2(format_copy, len_before, ret, &i);
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*ret;
	int		flags[6];
	char	*format_copy;
	va_list	list;

	format_copy = (char *)format;
	va_start(list, format);
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = get_ret(format_copy, list, ret, flags);
	ft_putstr(ret);
	i = ft_strlen(ret);
	va_end(list);
	free(ret);
	return (i);
}
