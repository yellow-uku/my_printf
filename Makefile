# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 16:59:11 by pkayleen          #+#    #+#              #
#    Updated: 2021/03/21 16:16:03 by pkayleen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c \
		parser/main_parse.c \
		parser/parse2.c \
		specifiers/types_c_s.c \
		specifiers/type_p.c \
		specifiers/type_x.c \
		specifiers/type_upper_x.c \
		specifiers/type_u.c \
		specifiers/type_d_i.c \
		specifiers/utils.c \
		specifiers/utils2.c \

SRC = $(FILES)
OBJ = $(FILES:.c=.o)
INC = ft_printf.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
lib:
	@make -C $(LIBFT_DIR)
objects:
	mkdir -p objects/
.c.o: $(SRC) | objects
	gcc $(FLAGS) -I $(INC) -o $@ -c $<
$(NAME): $(OBJ) lib
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) has been compiled"
clean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ)
	rm -rf ./objects
	@echo "Objects were deleted"
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf ./objects
	@echo "libftprintf.a was deleted"
re: fclean all

norm:
	@norminette ft_printf.c specifiers/*.c includes/* libft/* parser/*

.PHONY: all, clean, fclean, re

run:
	make
	gcc main.c libftprintf.a
	./a.out
