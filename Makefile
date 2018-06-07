# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 15:40:02 by htkachuk          #+#    #+#              #
#    Updated: 2018/04/02 15:40:04 by htkachuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = src/vector_1.c src/main.c src/create_win_img.c src/ft_key.c src/parsing.c \
		src/quadratic_equation.c src/transform_coord.c src/vector.c src/ray.c \
		src/color_math.c src/intersect.c src/def_figure.c src/scene_5.c

OBJ = $(SRC:.c=.o)

FLAG =  -O3 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C ./libft	
	@ gcc -o $(NAME) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit 

%.o: %.c src/rtv1.h
	@ gcc -c $(FLAG) -o $@ $<

clean:
	@ /bin/rm -f $(OBJ)
	@ make -C ./libft clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C ./libft fclean

re: fclean all

.PHONY: re all clean fclean
	