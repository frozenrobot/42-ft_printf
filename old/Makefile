# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 23:02:53 by kgulati           #+#    #+#              #
#    Updated: 2021/06/04 23:16:48 by kgulati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME = libftprintf.a
 INCLUDES = libftprintf.h
 FILES = convert_base_hex.c \
		convert_base_hex_cap.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_printf.c

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
