# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 10:55:13 by ehelmine          #+#    #+#              #
#    Updated: 2020/10/30 09:15:50 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c validate_file.c

OBJECT = $(SRCS:.c=.o)

INCLUDE = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

MAKE = make

all: $(NAME)

$(NAME):
	$(MAKE) -C libft
	gcc $(CFLAGS) -c $(SRCS)
	gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(INCLUDE) -L /Users/ellahelminen/Downloads/minilibx -L /opt/X11/include/X11 \
	-lmlx -I /usr/local/include/ -L /opt/X11/lib/ -lX11 -lXext -framework OpenGL -framework Appkit
#	gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(INCLUDE) -L /usr/local/lib \
	-lmlx -framework OpenGL -framework Appkit -I header.h

clean:
	$(MAKE) -C libft clean
	@rm -f $(OBJECT)

fclean: clean
	$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all