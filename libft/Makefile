# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 13:01:03 by ehelmine          #+#    #+#              #
#    Updated: 2020/10/30 15:41:25 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_atoi.c ft_strlen.c ft_strcmp.c ft_putnbr.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strclr.c ft_strcat.c ft_strncmp.c \
	ft_putendl.c ft_strlcat.c ft_bzero.c ft_strncat.c ft_strchr.c ft_strrchr.c \
	ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strstr.c ft_strnstr.c \
	ft_tolower.c ft_toupper.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memmove.c ft_strequ.c ft_strnequ.c ft_memalloc.c \
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strtrim.c ft_strjoin.c ft_striter.c \
	ft_striteri.c ft_strsplit.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_itoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	ft_check_int.c ft_islower.c ft_isupper.c ft_isspace.c ft_strndup.c \
	get_next_line.c

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME):
		@gcc -Wall -Wextra -Werror -c -I includes $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJS) 

fclean: clean
		@rm -f $(NAME)

re: fclean all
