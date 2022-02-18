/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conversions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:07:10 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/21 18:33:58 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convert_base_hex_long_recurse(char *ret, unsigned long nbr)
{
	char	*base;

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

char	*convert_base_hex_long(unsigned long nbr)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_long_recurse(ret, nbr);
	return (ret);
}

char	*convert_base_hex_cap_recurse(char *ret, unsigned int nbr)
{
	char	*base;

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

char	*convert_base_hex_cap(unsigned int nbr)
{
	char	*ret;

	ret = malloc(sizeof(char));
	ret[0] = '\0';
	ret = convert_base_hex_cap_recurse(ret, nbr);
	return (ret);
}
