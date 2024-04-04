# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrances <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:44:00 by jfrances          #+#    #+#              #
#    Updated: 2023/04/02 13:11:37 by jfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BNAME = so_long_bonus

SRC	=	gnl/get_next_line.c gnl/get_next_line_utils.c map_parsing/map_parse.c\
		map_parsing/parse_map_utils.c printf/ft_printf.c printf/ft_printf_utils.c\
		printf/hex_check.c grid_management/counter.c grid_management/key_handles.c\
		grid_management/hooks_initialze.c grid_management/kich_lib.c main.c\
		grid_management/update_frames.c grid_management/memory.c

BSRC =	gnl/*.c printf/*.c bonus/*.c main.c

HEADER = so_long.h so_long_structs.h

OBJ = $(SRC:.c=.o)

BOBJ = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dir $(BSRC)))))

FLGS = -Wall -Werror -Wextra

.c.o:
	cc $(FLGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJ) $(HEADER)
	cc $(FLGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $@

bonus:clean $(BOBJ) $(OBJ) $(HEADER)
	cc $(FLGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)

fclean:clean
	rm -f $(NAME)
	rm -f $(BNAME)

re:	fclean all

.PHONY: all bonus clean fclean re
