/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:55:48 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/12 17:50:56 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcatchar(char *dest, char c)
{
	int i;
	char *new;

	i = 0;
	new = malloc((ft_strlen(dest) + 2) * sizeof(char));
	if (!new)
		return (NULL);
	while (dest[i] != '\0')
	{
		new[i] = dest[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0'
	free(dest);
	return (new);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char *)(dest + i - 1) = *(unsigned char *)(src + i - 1);
			i--;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*both;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	both = malloc ((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, s1, ft_strlen(s1));
	ft_memmove(both + ft_strlen(s1), s2, ft_strlen(s2));
	both[size - 1] = '\0';
	free(s1);
	free(s2);
	return (both);
}

// static int	ft_isspace(char c)
// {
// 	if (c == ' ' || c == '\f' || c == '\n'
// 		|| c == '\r' || c == '\t' || c == '\v')
// 		return (1);
// 	return (0);
// }

// static int	ten_power(int exp)
// {
// 	if (exp == 0)
// 		return (1);
// 	return (10 * ten_power(exp - 1));
// }

// static int	convert_to_int(char *str, int i, int size)
// {
// 	int	result;
// 	int	j;

// 	result = 0;
// 	j = 1;
// 	while (j <= size)
// 	{
// 		result += ((str[i] - '0') * ten_power(size - j));
// 		i++;
// 		j++;
// 	}
// 	return (result);
// }

// int	ft_atoi(char *str)
// {
// 	int	i;
// 	int	multiply;
// 	int	size;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	multiply = 1;
// 	while (ft_isspace(str[i]))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			multiply *= -1;
// 		i++;
// 	}
// 	size = check_size_ahead(str, i);
// 	return (multiply * convert_to_int(str, i, size));
// }

// int atoi_string(char *ptr, int i)
// {
// 	int i2;
// 	int ret;
// 	int size;

// 	i2 = 1;
// 	ret = 0;
// 	while (ptr[i2] >= '0' && ptr[i2] <= '9')
// 		i2++;
// 	size = i2 - i;
// 	return (convert_to_int(ptr, i, size));
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

int zero_flag(char *ptr, int i, va_list list)
{
	int n;

	n = 0;
	if 
}

int is_flag(char c)
{
	if (c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

int is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int flags(char *ptr, int i, va_list list)
{
	if (ptr[i] == 0)
		return (zero_flag(ptr, i, list));



	else (return )
}

int	ft_printf(const char *format, ...)
{
	va_list list;
	char *ptr;
	int i;
	char	*ret;

	va_start(list, format);
	ptr = (char *)format;
	i = 0;
	ret = "";
	while (ptr[i] != '\0')
	{
		while (ptr[i] != '%' && ptr[i] != '\0')
		{
			ft_strcatchar(ret, ptr[i]);
			i++;
		}
		if (ptr[i] == '%')
		{
			if (is_flag(ptr[i + 1]))
			{

			}
			else if (is_conversion(ptr[i + 1]))
			{

			}
			else{
				ft_strcatchar(ret, ptr[i]);
				i++;
			}
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

	char c = 'd';
	ft_printf("%chello\n%c\n", c, c);
}