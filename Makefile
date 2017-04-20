# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 14:18:14 by mmartins          #+#    #+#              #
#    Updated: 2017/04/10 12:56:27 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		maxprintf
CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror

SRCS =		main.c \
			conv_int.c \
			flags.c \
			ft_printf2.c \
			conv_uint.c \
			mod.c \
			conv_str.c \
			conv_char.c \

OBJS =		$(SRCS:.c=.o)

LIBFT_PATH =	./libft

all:	$(NAME)

$(NAME):$(OBJS)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAG) $(SRCS) -I. -L./libft -lft -o $(NAME) -g

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
