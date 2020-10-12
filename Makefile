# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 15:19:02 by atomatoe          #+#    #+#              #
#    Updated: 2020/10/08 15:31:52 by atomatoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEAD = /includes
SRCS = ./srcs/
FUNC =	main ft_bzero ft_calloc ft_memset ft_putendl_fd ft_strncmp \
get_next_line_utils get_next_line ft_draw ft_draw2 ft_error ft_init_struct \
ft_init_textures ft_init_window ft_key ft_key2 ft_list ft_paint ft_parse_utils \
ft_parse_utils2 ft_parse ft_parse2 ft_parse3 ft_screenshot ft_sprite_get ft_sprite \
ft_utils

SRC = $(addprefix $(SRCS), $(addsuffix .c, $(FUNC)))
OBJ = $(addprefix $(SRCS), $(addsuffix .o, $(FUNC)))
FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./mlx/
	@mv ./mlx/libmlx.dylib .
	@gcc -g -I $(HEAD) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all