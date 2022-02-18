# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 16:19:54 by kgulati           #+#    #+#              #
#    Updated: 2021/06/22 12:54:06 by kgulati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = libftprintf.h
FILES = atoi.c \
		basic_str.c \
		convert_flags.c \
		ft_printf.c \
		nbr_conversions1.c \
		nbr_conversions2.c \
		parse_flags.c \
		produce_string.c \
		str_add_left_right.c \
		str_char_join.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all