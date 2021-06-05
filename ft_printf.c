/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:55:48 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/04 23:48:53 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int flags(char *ptr, va_list list)
// {
	
// }

int	conversions2(char *ptr, int n, va_list list)
{
	int i;
	long l;

	if (ptr[n] == 'c')
	{
		i = va_arg(list, int);
		ft_putchar(i);
	}
	else if (ptr[n] == 'i' || *ptr == 'd')
	{
		i = va_arg(list, int);
		ft_putnbr(i);
	}
	else if (ptr[n] == 'p')
	{
		l = va_arg(list, long);
		ft_putstr("0x");
		putlong_hex(l);
	}
	else
		return (0); //case for invalid conversion characters
	return (1);
}

int	conversions(char *ptr, int n, va_list list)
{
	unsigned int i;
	char *s;

	if (ptr[n] == 'x')
	{
		i = va_arg(list, unsigned int);
		convert_base_hex(i);
	}
	else if (ptr[n] == 'X')
	{
		i = va_arg(list, unsigned int);
		convert_base_hex_cap(i);
	}
	else if (ptr[n] == '%')
		ft_putchar('%');
	else if (ptr[n] == 'u')
	{
		i = va_arg(list, unsigned int);
		ft_putnbr(i);
	}
	else if (ptr[n] == 's')
	{
		s = va_arg(list, char *);
		ft_putstr(s);
	}
	else
		return (conversions2(ptr, n, list));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list list;
	char *ptr;
	int i;

	va_start(list, format);
	ptr = (char *)format;
	i = 0;
	while (ptr[i] != '\0')
	{
		while (ptr[i] != '%' && ptr[i] != '\0')
		{
			ft_putchar(ptr[i]);
			i++;
		}
		if (ptr[i] == '%')
		{
			i++;
			// if (*ptr == '-' || *ptr == '0' || *ptr == '.' || *ptr == '*'
			// 	|| (*ptr >= '0' && *ptr <= '9'))
			// 	ptr += flags(ptr, list);
			/*else*/ if (ptr[i] == 'c' || ptr[i] == 's' || ptr[i] == 'p' || ptr[i] == 'd'
				|| ptr[i] == 'i' || ptr[i] == 'u' || ptr[i] == 'x' || ptr[i] == 'X'
				|| ptr[i] == '%')
				i += conversions(ptr, i, list);
		}
	}
	va_end(list);
	return (1);
}

int main(void)
{
	// int i = -98;
	// ft_printf("%chello\n", i);


	// char c[] = "hello";
	// ft_printf("%shello\n", c);
	// convert_base_hex_cap(500);

	
}