# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 10:55:13 by ehelmine          #+#    #+#              #
#    Updated: 2020/12/09 01:41:19 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c validate_file.c print_fdf.c keys_and_events.c set_values.c \
	print_projs.c help_functions.c

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
	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB) -L /usr/local/lib/ \
	-lmlx -I /usr/local/include/ -L /usr/local/include/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit
	@echo "Compiling fdf"

clean:
	@$(MAKE) -C libft clean
	@echo "Removing .o files"
	@rm -f $(OBJECT)

fclean: clean
	@$(MAKE) -C libft fclean
	@echo "Removing fdf executable and libft.a"
	@rm -f $(NAME)

re: fclean all