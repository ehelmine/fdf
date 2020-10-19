# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 10:55:13 by ehelmine          #+#    #+#              #
#    Updated: 2020/10/16 10:31:41 by ehelmine         ###   ########.fr        #
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
	gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(INCLUDE) -L /usr/local/lib -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit
#	gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(INCLUDE) -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -I header.h

clean:
	$(MAKE) -C libft clean
	@rm -f $(OBJECT)

fclean: clean
	$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all