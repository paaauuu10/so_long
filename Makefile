# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:46:45 by pbotargu          #+#    #+#              #
#    Updated: 2024/02/08 15:27:49 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES = main.c error.c open_map.c gnl/get_next_line_utils.c gnl/get_next_line.c

MLX = -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

INCLUDE = -I includes -I libft
LIBFT_PATH = ./libft
LIBFT = libft/libft.a

all: makemlx $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CC) $(FLAGS) mlx/libmlx.a $(MLX) $(OBJECTS) -o $(NAME)

%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

makemlx: 
	$(MAKE) -C mlx/

-include $(DEPS)

clean:
	RM $(OBJECTS) $(DEPS) $(NAME)
	$(MAKE) clean -C mlx

fclean: clean
	RM $(NAME)

re: fclean all

.PHONY: all clean fclean re makemlx