# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:47:15 by achansar          #+#    #+#              #
#    Updated: 2022/12/16 10:26:50 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = fdf


SRC = 	fdf_main \
		draw \
		key \
		matrix \
		readfile \
		window \
		scale \
		isometric \
		bresenham \
		fdf_utils

C_FILES = $(SRC:=.c)
OBJ = $(SRC:=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra -O1 -O2 -O3
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

#LIBFT
LBFT = ./libft/
LBFT_LIB = $(addprefix $(LBFT), ft.a)
LBFT_INC = -I $(LBFT)
LBFT_LINK = -L $(LBFT) -l ft

#RULES
all: $(LBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LBFT_LINK) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c -I /usr/local/include $(LBFT_INC) $< -o $@

$(LBFT_LIB):
	make -C $(LBFT)

clean:
	make -C $(LBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re