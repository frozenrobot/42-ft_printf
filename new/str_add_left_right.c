/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add_left_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:10:38 by kgulati           #+#    #+#             */
/*   Updated: 2021/06/22 16:53:10 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*space_add_right(char *str)
{
	str = charjoin(str, ' ');
	return (str);
}

char	*space_add_left(char *str)
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

char	*zero_add_left(char *str)
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

char	*char_add_left(char *str, char c)
{
	int		size;
	char	*both;

	if (!str)
		return (NULL);
	size = ft_strlen(str) + 2;
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	both[0] = c;
	ft_memmove(both + 1, str, ft_strlen(str));
	both[size - 1] = '\0';
	free(str);
	return (both);
}

char	*char_del_left(char *str)
{
	int		size;
	char	*both;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	both = malloc((size) * sizeof(char));
	if (!both)
		return (NULL);
	ft_memmove(both, str + 1, ft_strlen(str) - 1);
	both[size - 1] = '\0';
	free(str);
	return (both);
}
