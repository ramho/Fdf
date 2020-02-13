# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 17:46:55 by rhoorntj          #+#    #+#              #
#    Updated: 2020/02/13 19:51:21 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/main.c src/read.c src/draw.c src/projection.c src/deal_key.c\
	  src/line_n_color.c
INC = inc/fdf.h

FLAGS =  -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	make re -C libft/
	make re -C minilibx_macos/
	gcc $(SRC) -I $(INC) -o $(NAME) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -fsanitize=address

clean:
	/bin/rm -f *.o
	/bin/rm -f libft/*.o
	/bin/rm -f minilibx_macos/*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a
	/bin/rm -f minilibx_macos/libmlx.a

re: fclean all

.PHONY : all clean fclean re makelibft makeminilibx
