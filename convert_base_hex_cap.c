/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base_hex_cap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:33:33 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/04 23:43:09 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_base_hex_cap(int nbr) //negatives?
{
	char *base;

	base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		convert_base_hex_cap(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
	else
		ft_putchar(base[nbr]);
	return ;
}