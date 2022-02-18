#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

long mod(long nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

    i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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

char	*strjoin(char *s1, char *s2)
{
	int		size;
	char	*both;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, s1, ft_strlen(s1));
	ft_memmove(both + ft_strlen(s1), s2, ft_strlen(s2));
	both[size - 1] = '\0';
	// free(s1);
	free(s2);
	return (both);
}

char	*strjoin_frees1(char *s1, char *s2)
{
	int		size;
	char	*both;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, s1, ft_strlen(s1));
	ft_memmove(both + ft_strlen(s1), s2, ft_strlen(s2));
	both[size - 1] = '\0';
	free(s1);
	free(s2);
	return (both);
}

char *charjoin(char *str, char c)
{
	int		size;
	char	*both;

	size = ft_strlen(str) + 2;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str, ft_strlen(str));
	both[size - 2] = c;
	both[size - 1] = '\0';
	// if (str[0] != '\0')
	free(str);
	return (both);
}


int	check_negative(char *ret, int nb)
{
	if (nb < 0)
	{
		ret = charjoin(ret, '-');
		nb = -nb;
	}
	return (nb);
}

char *putnbr_recurse(char *ret, int nb)
{
	if (nb > 9)
	{
		ret = putnbr_recurse(ret, nb / 10);
		ret = putnbr_recurse(ret, nb % 10);
	}
	else
		ret = charjoin(ret, '0' + nb);
	return (ret);
}

char *putnbr(int nb)
{
	char *ret;

	if (nb == -2147483648)
		return ("-2147483648");
	else if (nb == 0)
	    return ("0");
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	nb = check_negative(ret, nb);
	ret = putnbr_recurse(ret, nb);
	return (ret);
}

char *convert_base_hex_recurse(char *ret, int nbr)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ret = convert_base_hex_recurse(ret, nbr / 16);
		ret = charjoin(ret, base[nbr % 16]);
	}
	else
		ret = charjoin(ret, base[nbr]);
	return (ret);
}

char *convert_base_hex(int nbr)
{
	char *ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_recurse(ret, nbr);
	return (ret);
}

char *convert_base_hex_long_recurse(char *ret, unsigned long nbr)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ret = convert_base_hex_long_recurse(ret, nbr / 16);
		ret = charjoin(ret, base[nbr % 16]);
	}
	else
		ret = charjoin(ret, base[nbr]);
	return (ret);
}

char *convert_base_hex_long(unsigned long nbr)
{
	char *ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_long_recurse(ret, nbr);
	return (ret);
}

char *convert_base_hex_cap_recurse(char *ret, int nbr)
{
	char *base;

	base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ret = convert_base_hex_cap_recurse(ret, nbr / 16);
		ret = charjoin(ret, base[nbr % 16]);
	}
	else
		ret = charjoin(ret, base[nbr]);
	return (ret);
}

char *convert_base_hex_cap(int nbr)
{
	char *ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_cap_recurse(ret, nbr);
	return (ret);
}

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

char *space_add_right(char *str)
{
	str = charjoin(str, ' ');
	return (str);
}

char *space_add_left(char *str)
{
	int		size;
	char	*both;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 2;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	both[0] = ' ';
	ft_memmove(both + 1, str, ft_strlen(str));
	both[size - 1] = '\0';
	free(str);
	return (both);
}

char *zero_add_left(char *str)
{
	int		size;
	char	*both;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 2;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	both[0] = '0';
	ft_memmove(both + 1, str, ft_strlen(str));
	both[size - 1] = '\0';
	free(str);
	return (both);
}

char *strtrim(char *str, int size)
{
	char *both;

	// if (ft_strlen(str) <= size)
	// 	return (str);
	both = (char *)malloc((size + 1) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str, size);
	both[size] = '\0';
	// free(str);
	return (both);
}

int is_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

// ___ end_conversion(___)
// {

// }

void reset_flags(int *flags)
{
	int i;

	i = 0;
	while (i < 5)
	{
		flags[i] = -1;
		i++;
	}
}

void parse_flags(int *flags, char *format, int i, va_list list)
{
	int temp;

	if (format[i] == '0')
	{
		while (format[i] == '0')
			i++;
		flags[0] = 1;
	}
	if (format[i] == '*')
	{
		temp = va_arg(list, int);
		if (temp < 0)
		{
			flags[2] = 1;
			temp *= -1;
		}
		flags[3] = temp;
		i++;
	}
	else
	{
		while (format[i] == '-')
		{
			flags[2] = 1;
			i++;
		}
		if (format[i] == '*')
		{
			temp = va_arg(list, int);
			if (temp < 0)
			{
				temp *= -1;
				flags[2] = -1;
			}
			flags[3] = temp;
			i++;
		}
		else
		{
			flags[3] = ft_atoi(format, i);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
	}
	if (format[i] == '.')
	{
		flags[1] = 0;
		i++;
		if (format[i] == '*')
		{
			flags[1] = va_arg(list, int);
			i++;
		}
		else
		{
			if (format[i] == '-')
			{
				i++;
				if (format[i] == '*')
				{
					temp = va_arg(list, int);
						flags[1] = temp * -1;
					i++;
				}
				else
				{
					while (format[i] == '-')
						i++;
					flags[1] = -1 * ft_atoi(format, i);
					while (format[i] >= '0' && format[i] <= '9')
						i++;
				}
			}
			else
			{
				flags[1] = ft_atoi(format, i);
				while (format[i] >= '0' && format[i] <= '9')
					i++;
			}

		}
		if (flags[1] < 0)
			flags[1] = -1;
	}
	if (!is_conversion(format[i]))
		flags[4] = 1;

	// while (format[i] == '0') //use atoi
	// {
	// 	flags[0] = 1;
	// 	i++;
	// }
	// while (is_flag(format[i]))
	// {
	// 	if (format[i] == '.') //atoi or default
	// 		flags[1] = 1;
	// 	if (format[i] == '-') //atoi
	// 		flags[2] = 1;
	// 	// if (format[i] == '*') //normal atoi on va_arg //HANDLE FIELD WIDTH
	// 	// 	flags[3] = 1;
	// 	i++;
	// }
}

char *unsigned_int_conversions(char *format, int j, va_list list)
{
	unsigned int i;

	i = va_arg(list, unsigned int);
	if (format[j] == 'c')
		return (charjoin("", i));
	else if (format[j] == 'u')
		return (putnbr(i));
	else if (format[j] == 'x')
		return (convert_base_hex(i));
	else if (format[j] == 'X')
		return (convert_base_hex_cap(i));
	else
		return ("ERROR");
}

char *convert_to_string(char *format, int j, va_list list) //int flags[] ?
{
	if (format[j] == 'c' || format[j] == 'u' || format[j] == 'x' || format[j] == 'X')
		return (unsigned_int_conversions(format, j, list));
	else if (format[j] == 'i' || format[j] == 'd')
		return (putnbr(va_arg(list, int)));
	else if (format[j] == 's')
		return (va_arg(list, char *));
	else if (format[j] == '%')
		return (charjoin("", '%'));
	else if (format[j] == 'p')
		return (strjoin("0x", convert_base_hex_long((unsigned long)va_arg(list, unsigned long))));
	else
		return ("ERROR");
}

char *apply_flags(char *str, int *flags, char conversion)
{
	int prec;
	int fw;
	int left;
	int zero;

	zero = flags[0];
	prec = flags[1];
	left = flags[2];
	fw = flags[3];
	if (conversion == 's' && prec == -1)
		prec = ft_strlen(str);
	if (prec != -1 && conversion == 's')
		str = strtrim(str, prec);
	if (zero != -1 && (conversion == 'd' || conversion == 'i'
		|| conversion == 'u' || conversion == 'x' || conversion == 'X'))
	{
		while (ft_strlen(str) < fw)
			str = zero_add_left(str);
	}
	else if (prec != -1 && (conversion == 'd' || conversion == 'i'
			|| conversion == 'u' || conversion == 'x' || conversion == 'X'))
	{
		while (ft_strlen(str) < prec)
			str = zero_add_left(str);
	}
	if (left == -1 && fw != -1)
	{
		while (ft_strlen(str) < fw)
			str = space_add_left(str);
	}
	if (left == 1 && fw != -1)
	{
		while (ft_strlen(str) < fw)
			str = space_add_right(str);
	}
	return (str);
}

char *produce_string(int *flags, char *format, int i, va_list list)
{
	int j;
	char *str;
	char conversion;

	j = i;
	str = "";
	if (flags[4] == 1)
		return ("");
	while (format[j] == '0')
		j++;
	while (is_flag(format[j]))
		j++;
	if (is_conversion(format[j]))
	{
		conversion = format[j];
		str = convert_to_string(format, j, list);
	}
	if (ft_strlen(str) == 0)
		return ("");
	else
		return (apply_flags(str, flags, conversion));
}

int ft_printf(const char *format, ... )
{
	int i;
	char	*ret;
	int flags[5];
	int len_before;
	char *format_copy;
	va_list list;

	format_copy = (char *)format;
	va_start(list, format);
	i = 0;
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	// ret = "";
	while (format_copy[i] != '\0')
	{
		while (format_copy[i] != '%' && format_copy[i] != '\0')
		{
			ret = charjoin(ret, format_copy[i]);
			i++;
		}
		if (format_copy[i] == '%')
		{
		    i++;
			reset_flags(flags);
			parse_flags(flags, format_copy, i, list);
			len_before = ft_strlen(ret);
			ret = strjoin_frees1(ret, produce_string(flags, format_copy, i, list));
			if (len_before == ft_strlen(ret))
			{
				ret = charjoin(ret, '%');
				i++;
			}
			else
			{
				while (is_flag(format_copy[i]) || (format_copy[i] >= '0' && format_copy[i] <= '9'))
					i++;
				i++;
			}
		}
	}
	ft_putstr(ret);
	i = ft_strlen(ret);
	va_end(list);
	free(ret); //?
	return (i);
}

#include <stdio.h>
int main(void)
{
	// char p[] = "banananana";
	// ft_printf("hel%10.3s\n", "hello");
	ft_printf("%.4i\n", 20);
	// printf("%.2p\n", NULL);
	ft_printf("%0000-00s24ksss%.4iii%ddd%04i\n%.8x", "hello", 20, 30, 500, 12345);
}