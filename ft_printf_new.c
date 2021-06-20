

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
	free(s1);
	return (both);
}

char *charjoin(char *str, char c)
{
	int		size;
	char	*both;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 2;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str, ft_strlen(str));
	both[size - 2] = c;
	both[size - 1] = '\0';
	free(str);
	return (both);
}


int	check_negative(char *ret, int nb)
{
	if (nb < 0)
	{
		charjoin(ret, '-');
		nb = -nb;
	}
	return (nb);
}

void putnbr_recurse(char *ret, int nb)
{
	if (nb > 9)
	{
		putnbr_recurse(nb / 10);
		putnbr_recurse(nb % 10);
	}
	else
		charjoin('0' + nb);
}

char *putnbr(int nb)
{
	char *ret;

	if (nb == -2147483648)
		return ("-2147483648");
	ret = "";
	nb = check_negative(ret, nb);
	putnbr_recurse(ret, nb);
	return (ret);
}

void	convert_base_hex_recurse(char *ret, int nbr)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		convert_base_hex_recurse(nbr / 16);
		charjoin(ret, base[nbr % 16]);
	}
	else
		charjoin(ret, base[nbr]);
	return (ret);
}

void	convert_base_hex(int nbr)
{
	char *ret;

	ret = "";
	convert_base_hex_recurse(ret, nb);
	return (ret);
}

void	convert_base_hex_cap_recurse(char *ret, int nbr)
{
	char *base;

	base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		convert_base_hex_cap_recurse(nbr / 16);
		charjoin(ret, base[nbr % 16]);
	}
	else
		charjoin(ret, base[nbr]);
	return (ret);
}

void	convert_base_hex_cap(int nbr)
{
	char *ret;

	ret = "";
	convert_base_hex_cap_recurse(ret, nb);
	return (ret);
}

char *space_add_right(char *str)
{
	charjoin(str, ' ');
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

	if (ft_strlen(str) <= size)
		return (str);
	both = malloc((size + 1) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str, size);
	both[size - 1] = '\0';
	free(str);
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

void reset_flags(int *flags[])
{
	int i;

	i = 0;
	while (i < 5)
	{
		flags[i] = -1;
		i++;
	}
}

void parse_flags(int *flags[], const char *format, int i)
{
	while (format[i] == '0') //use atoi
	{
		flags[0] = 1;
		i++;
	}
	while (is_flag(format[i]))
	{
		if (format[i] == '.') //atoi or default
			flags[1] = 1;
		if (format[i] == '-') //atoi
			flags[2] = 1;
		// if (format[i] == '*') //normal atoi on va_arg //HANDLE FIELD WIDTH
		// 	flags[3] = 1;
		i++;
	}
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
}

char *convert_to_string(char *format, int j, va_list list, int *flags[]) //int flags[] ?
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
		return //////////////////////////////////////////////////////
}

char *apply_flags(char *str, int *flags[], char conversion)
{
	int prec;
	int fw;
	int left;
	int zero;

	zero = flags[0];
	prec = flags[1];
	left = flags[2];
	fw = flags[3];
	if (prec != -1 && conversion == 's')
		str = strtrim(str, prec);
	if (zero != -1 && (conversion == 'd' || conversion == 'i'
		|| conversion == 'u' || conversion == 'x' || conversion == 'X'))
	{
		while (ft_strlen(str) < zero)
			zero_add_left(str);
	}
	else if (prec != -1 && (conversion == 'd' || conversion == 'i'
			|| conversion == 'u' || conversion == 'x' || conversion == 'X'))
	{
		while (ft_strlen(str) < prec)
			zero_add_left(str);
	}
	if (left == -1 && fw != -1)
	{
		while (ft_strlen(str) < fw)
			space_add_left(str);
	}
	else if (left == 1 && fw != -1)
	{
		while (ft_strlen(str) < fw)
			space_add_right(str);
	}
}

char *produce_string(int *flags[], char *format, int i, va_list list)
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
		str = convert_to_string(format, j, list, flags);
	}
	if (ft_strlen(str) == 0)
		return ("");
	else
		return (apply_flags(str, flags, conversion));
}

int ft_printf(const char *format, ... )
{
	va_list list;
	int i;
	char	*ret;
	int *flags[5];
	int len_before;

	va_start(list, format);
	i = 0;
	ret = "";
	while (format[i] != '\0')
	{
		while (format[i] != '%')
		{
			charjoin(ret, format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			reset_flags(flags);
			parse_flags(flags, format, i + 1);
			len_before = ft_strlen(ret);
			strjoin(ret, produce_string(flags, format, i + 1, list));
			if (len_before == ft_strlen(ret))
			{
				charjoin(ret, '%');
				i++;
			}
			else
			{
				while (format[i] == '0')
					i++;
				while (is_flag(format[i]))
					i++;
				i++;
			}
		}
	}
	ft_putstr(ret);
	free(ret); //?
	return (ft_strlen(ret));
}