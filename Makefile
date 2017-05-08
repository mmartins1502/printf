NAME = libftprintf.a

H_DIR = .
C_DIR = src
O_DIR = objects

LINKS = -I$(H_DIR)

C_FILES = src/conv_int.c \
					src/flags.c \
					src/ft_printf2.c \
					src/conv_uint.c \
					src/mod.c \
					src/conv_str.c \
					src/conv_char.c \
					src/conv_wchar.c \
					src/ft_wctomb.c \
					src/conv_wstr.c \
					src/ft_uitoa.c \
					src/ft_isdigit.c \
					src/ft_memalloc.c \
					src/ft_memset.c \
					src/ft_strnew.c \
					src/ft_atoi.c \
					src/ft_memcpy.c \
					src/ft_putnstr.c \
					src/ft_strlen.c \
					src/ft_itoa_base.c \
					src/conv_pointer.c \
					src/conv_wstr.c

O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $@ $^
	@echo "\033[33;32m===      LIBFT    FINISHED        === \n		√\n"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) $(LINKS) -o $@ -c $<

clean:
	@echo "\033[33;32m===    DELETING   OBJECTS         === \n 		√\n"
	@rm -rf $(O_DIR)


fclean: clean
	@echo "\033[33;32m===    DELETING   libftprintf.a   === \n 		√\n"
	@rm -f $(NAME)

re : fclean all
