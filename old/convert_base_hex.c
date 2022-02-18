/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:32:39 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/04 23:42:45 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_base_hex(int nbr) //negatives?
{
	char *base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		convert_base_hex(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
	else
		ft_putchar(base[nbr]);
	return ;
}

void	putlong_hex(long nbr) //negatives?
{
	char *base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		putlong_hex(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
	else
		ft_putchar(base[nbr]);
	return ;
}