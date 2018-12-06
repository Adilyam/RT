#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atilegen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 19:59:37 by atilegen          #+#    #+#              #
#    Updated: 2018/12/06 15:28:34 by atilegen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = RT
MLXFLAGS = -lpthread -lmlx -framework OpenGL -framework AppKit
CC = gcc -Wall -Wextra -Werror -O3

CFLAGS = -I ./includes/
HEADERS = 	includes/rt.h
SRCS =	src/main/main.c \
		src/main/ft_key.c				\
		src/main/transform_coord.c		\
		src/main/ray.c					\
		src/math/quadratic_equation.c	\
		src/math/color_math.c			\
		src/math/intersect.c			\
		src/define/def_figure.c			\
		src/define/create_win_img.c 	\
		src/vectors/vector_1.c			\
		src/vectors/vector.c			\
		src/parse/parse5.c				\
		src/parse/parse_names.c			\
		src/parse/parse_checks.c        \
 		src/parse/parse_cam.c           \
        src/parse/parse_lgt.c           \
		src/parse/parse_obj.c           \
		src/parse/parse1.c				\
		src/define/color_filters.c      \
 		src/define/ua_1.c           	\
        src/define/ua.c          		\
		src/math/figure_cut.c			\
		src/math/rotations.c

OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

.PHONY: re clean fclean all
all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@make -C $(LFT_DIR)
	@$(CC) -o $(NAME) $(CFLAGS) $(LFT_LNK) $(OBJ) $(MLXFLAGS)
	@echo "\033[34mRT \033[33mCOMPILED\033[0m"

clean:
	@make -C $(LFT_DIR) clean
	@rm -f src/main/*.o
	@rm -f src/math/*.o
	@rm -f src/vectors/*.o
	@rm -f src/parse/*.o
	@rm -f src/define/*.o

fclean: clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
