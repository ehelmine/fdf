# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 10:55:13 by ehelmine          #+#    #+#              #
#    Updated: 2020/10/13 10:24:49 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c 

OBJECT = $(SRCS:.c=.o)

#INCLUDE = mlx.h

CFLAGS = -Wall -Wextra -Werror

MAKE = make

all: $(NAME)

$(NAME):
	$(MAKE) -C libft
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(CFLAGS) -o $(NAME) $(OBJECT) -L /usr/local/lib -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

clean:
	$(MAKE) -C libft clean
	@rm -f $(OBJECT)

fclean: clean
	$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all