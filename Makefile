# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 10:55:13 by ehelmine          #+#    #+#              #
#    Updated: 2020/11/04 10:39:09 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c validate_file.c print_fdf.c keys_and_events.c

OBJECT = $(SRCS:.c=.o)

LIB = libft/libft.a

INCLUDE = libft/includes/libft.h

CFLAGS = -Wall -Wextra -Werror

MAKE = make

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Sources to objects"
	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB) -L /Users/ellahelminen/Downloads/minilibx -L /opt/X11/include/X11 \
	-lmlx -I /usr/local/include/ -L /opt/X11/lib/ -lX11 -lXext -framework OpenGL -framework Appkit
#	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB) -L /usr/local/lib \
	-lmlx -framework OpenGL -framework Appkit -I header.h
	@echo "Compiling fdf"

clean:
	@$(MAKE) -C libft clean
	@rm -f $(OBJECT)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all