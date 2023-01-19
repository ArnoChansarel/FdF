# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:47:15 by achansar          #+#    #+#              #
#    Updated: 2023/01/19 18:00:59 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = fdf

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra -O1 -O2 -O3 
#SEG = -fsanitize=address -g
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
LBFT_PATH = ./functions/
LBFT = 	ft_atoi \
		ft_isdigit \
		ft_bzero \
		ft_memset\
	  	ft_split \
		ft_strjoin \
		ft_strlen \
		ft_substr \
		ft_strlcpy\
	  	get_next_line \
		get_next_line_utils \
	  	ft_printf \
		ft_printf_display
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@ $(CC) $(FLAGS) $(OBJ) $(LBFT_OBJ) $(MLX) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re