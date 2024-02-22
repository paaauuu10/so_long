# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:46:45 by pbotargu          #+#    #+#              #
#    Updated: 2024/02/22 14:53:17 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES = src/main.c src/error_and_free.c src/open_map.c \
gnl/get_next_line_utils.c gnl/get_next_line.c src/map_errors.c src/utils.c \
src/collect_info.c src/init_game.c src/movements.c print/baseprintf.c \
print/ft_printf_char.c print/ft_printf_string.c print/ft_printf_id.c 

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)

INCLUDE = -Iinc

all: makemlx $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(MLX) -o $(NAME)

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -MMD -c $< -o $@

makemlx: 
	$(MAKE) -C mlx/

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(DEPS) $(NAME)
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re makemlx
