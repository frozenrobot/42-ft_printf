/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:03:54 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 16:53:51 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

char	*charjoin(char *str, char c)
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
	free(str);
	return (both);
}

char	*strtrim(char *str, int size)
{
	char	*both;

	both = (char *)malloc((size + 1) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str, size);
	both[size] = '\0';
	return (both);
}

char	*empty_string(char *str)
{
	char	*empty;

	free(str);
	empty = malloc(sizeof(char));
	empty[0] = '\0';
	return (empty);
}
