/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:10:37 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 17:46:08 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(char *str);
long	mod(long nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	*ft_memmove(void *dest, const void *src, int n);
char	*strjoin(char *s1, char *s2);
char	*strjoin_frees1(char *s1, char *s2);
char	*charjoin(char *str, char c);
char	*check_negative(char *ret, long nb);
char	*putnbr_recurse(char *ret, long nb);
char	*putnbr(long nb);
char	*convert_base_hex_recurse(char *ret, unsigned int nbr);
char	*convert_base_hex(unsigned int nbr);
char	*convert_base_hex_long_recurse(char *ret, unsigned long nbr);
char	*convert_base_hex_long(unsigned long nbr);
char	*convert_base_hex_cap_recurse(char *ret, unsigned int nbr);
char	*convert_base_hex_cap(unsigned int nbr);
int		check_size_ahead(char *str, int i);
int		ten_power(int exp);
int		convert_to_int(char *str, int i, int size);
int		ft_atoi(char *str, int i);
int		ft_atoi_positive(char *str, int i);
char	*space_add_right(char *str);
char	*space_add_left(char *str);
char	*zero_add_left(char *str);
char	*char_add_left(char *str, char c);
char	*char_del_left(char *str);
char	*strtrim(char *str, int size);
int		is_flag(char c);
int		is_conversion(char c);
void	reset_flags(int *flags);
void	parse_flags_wc1(int *flags, va_list list);
void	parse_flags_notwc1(char *format, int *flags, int *i, va_list list);
void	parse_flags_dot_elseif(char *format, va_list list, int *flags, int *i);
void	parse_flags_dot(char *format, va_list list, int *flags, int *i);
void	parse_flags(int *flags, char *format, int i, va_list list);
char	*unsigned_int_conversions(char *format, int j, va_list list);
char	*convert_to_string(char *format, int j, va_list list, int *flags);
char	*apply_flags_neg_int(char *str, int fw);
char	*apply_flags_dot_int(char *str, int prec);
char	*apply_flags_sub(char *str, int *flags, char conversion);
char	*apply_flags(char *str, int *flags, char conversion);
char	*empty_string(char *str);
char	*produce_string(int *flags, char *format, int i, va_list list);
void	get_retif1(char *format_copy, int *flags, va_list list, int *i);
char	*get_retif2(char *format_copy, int len_before, char *ret, int *i);
char	*get_ret(char *format_copy, va_list list, char *ret, int *flags);
int		ft_printf(const char *format, ...);

#endif