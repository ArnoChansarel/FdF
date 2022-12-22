# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:47:15 by achansar          #+#    #+#              #
#    Updated: 2022/12/22 11:05:16 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = fdf

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra -O1 -O2 -O3 
SEG = -fsanitize=address -g
MLX = -lmlx -framework OpenGL -framework AppKit 

#FDF FILES
SRC_PATH = ./srcs/
SRC = 	fdf_main \
		draw \
		key \
		matrix \
		readfile \
		isometric \
		bresenham \
		fdf_utils
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

#LIBFT
LBFT = ./libft/
LBFT_LIB = $(addprefix $(LBFT), ft.a)
LBFT_INC = -I $(LBFT)
LBFT_LINK = -L $(LBFT) -lft

#RULES
all: $(LBFT_LIB) $(NAME)#                                          => attention ! relink du libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SEG) $(OBJ) $(MLX) $(LBFT_LINK) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $(LBFT_INC) $< -o $@

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