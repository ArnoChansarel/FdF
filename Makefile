# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:47:15 by achansar          #+#    #+#              #
#    Updated: 2022/12/20 17:42:14 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = fdf

#FDF FILES
SRC = 	fdf_main \
		draw \
		key \
		matrix \
		readfile \
		scale \
		isometric \
		bresenham \
		fdf_utils

SRC_PATH = ./srcs/

C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))
CC = gcc
FLAGS = -Wall -Werror -Wextra 
MLX = -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g 

#LIBFT
LBFT = ./libft/
LBFT_LIB = $(addprefix $(LBFT), ft.a)
LBFT_INC = -I $(LBFT)
LBFT_LINK = -L $(LBFT) -lft

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