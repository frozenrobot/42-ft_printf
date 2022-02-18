/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conversions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:06:47 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/21 18:33:43 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*check_negative(char *ret, long nb)
{
	if (nb < 0)
		ret = charjoin(ret, '-');
	return (ret);
}

char	*putnbr_recurse(char *ret, long nb)
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

char	*putnbr(long nb)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = check_negative(ret, nb);
	if (nb == -2147483648)
	{
		ret = charjoin(ret, '2');
		nb = 147483648;
	}
	nb = mod(nb);
	ret = putnbr_recurse(ret, nb);
	return (ret);
}

char	*convert_base_hex_recurse(char *ret, unsigned int nbr)
{
	char	*base;

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

char	*convert_base_hex(unsigned int nbr)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_recurse(ret, nbr);
	return (ret);
}
