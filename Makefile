# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 12:19:26 by mmartins          #+#    #+#              #
#    Updated: 2017/05/11 15:54:32 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	conv_int.c \
		flag.c \
		ft_printf.c \
		conv_uint.c \
		conv_str.c \
		conv_char.c \
		conv_wchar.c \
		ft_wctomb.c \
		ft_uitoa.c \
		ft_isdigit.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_strnew.c \
		ft_atoi.c \
		ft_memcpy.c \
		ft_putnstr.c \
		ft_strlen.c \
		ft_uitoa_base.c \
		conv_pointer.c \
		conv_wstr.c \
		ft_br_isconv_notflag.c \
		ft_width_prec_resetflag.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc -g -Wall -Wextra -Werror -c $*.c -o $@ -I.

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
