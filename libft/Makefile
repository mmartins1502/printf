# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 14:30:39 by mmartins          #+#    #+#              #
#    Updated: 2017/04/06 16:51:49 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_uitoa.c \
	ft_isdigit.c \
	ft_memalloc.c \
	ft_memset.c \
	ft_strnew.c \
	ft_atoi.c \
	ft_memcpy.c \
	ft_putnstr.c \
	ft_strlen.c \
	ft_itoa_base.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I.
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
