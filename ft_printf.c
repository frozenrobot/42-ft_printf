#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int flags(char *ptr)
{
	
}

int conversions(char *ptr, va_list list)
{
	int i;
	char *s;

	if (*ptr == 'c')
	{
		i = va_arg(list, int);
		ft_putchar(i);
	}
	else if (*ptr == 's')
	{
		s = va_arg(list, char *);
		ft_putstr(s);
	}
	
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *ptr;

	va_start(list, format);
	ptr = format;
	while (*ptr != '\0')
	{
		while (*ptr != '%')
		{
			ft_putchar(*ptr);
			ptr++;
		}
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '-' || *ptr == '0' || *ptr == '.' || *ptr == '*'
				|| (*ptr >= '0' && *ptr <= '9'))
				ptr += flags(ptr);
			else if (*ptr == 'c' || *ptr == 's' || *ptr == 'p' || *ptr == 'd'
				|| *ptr == 'i' || *ptr == 'u' || *ptr == 'x' || *ptr == 'X'
				|| *ptr = '%')
				ptr += conversions(ptr);
		}
	}
	va_end(list);
}