/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:52:39 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/04 23:28:11 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	convert_base_hex_cap(int nbr);
void	convert_base_hex(int nbr);
void	putlong_hex(long nbr);
int		check_negative(int nb);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
int		conversions2(char *ptr, int n, va_list list);
int		conversions(char *ptr, int n, va_list list);
int		ft_printf(const char *format, ...);

#endif