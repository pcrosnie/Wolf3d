# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by pcrosnie          #+#    #+#              #
#    Updated: 2016/09/03 10:04:12 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIB = libft/libft.a

GLIB = minilibx_macos/libmlx.a

SRC = main.c ft_check_wall.c

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

GFLAG = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(GFLAG) $(SRCO) $(LIB) $(GLIB)

clean:
	make -C libft clean
	make -C minilibx_macos clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
