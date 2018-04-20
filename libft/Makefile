# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctourret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:23:18 by ctourret          #+#    #+#              #
#    Updated: 2017/04/13 15:12:10 by ctourret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src/ft_atoi.c			\
	  src/ft_isalnum.c		\
	  src/ft_isalpha.c		\
	  src/ft_isascii.c		\
	  src/ft_isdigit.c		\
	  src/ft_isprint.c		\
	  src/ft_putchar.c		\
	  src/ft_putchar_fd.c	\
	  src/ft_putendl.c		\
	  src/ft_putendl_fd.c	\
	  src/ft_putnbr.c		\
	  src/ft_putnbr_fd.c	\
	  src/ft_putstr.c		\
	  src/ft_putstr_fd.c	\
	  src/ft_strcat.c		\
	  src/ft_strcmp.c		\
	  src/ft_strcpy.c		\
	  src/ft_strdup.c		\
	  src/ft_strequ.c		\
	  src/ft_strlen.c		\
	  src/ft_strncpy.c		\
	  src/ft_strstr.c		\
	  src/ft_tolower.c		\
	  src/ft_toupper.c		\
	  src/ft_bzero.c		\
	  src/ft_memset.c		\
	  src/ft_memcpy.c		\
	  src/ft_strncat.c		\
	  src/ft_strchr.c		\
	  src/ft_strrchr.c		\
	  src/ft_strnstr.c		\
	  src/ft_strncmp.c		\
	  src/ft_strclr.c		\
	  src/ft_striter.c		\
	  src/ft_striteri.c		\
	  src/ft_memccpy.c		\
	  src/ft_memchr.c		\
	  src/ft_memcmp.c		\
	  src/ft_strnequ.c		\
	  src/ft_memalloc.c		\
	  src/ft_memdel.c		\
	  src/ft_strnew.c		\
	  src/ft_strdel.c		\
	  src/ft_strtrim.c		\
	  src/ft_strmap.c		\
	  src/ft_strmapi.c		\
	  src/ft_strsub.c		\
	  src/ft_strjoin.c		\
	  src/ft_memmove.c		\
	  src/ft_itoa.c			\
	  src/ft_strsplit.c		\
	  src/ft_strlcat.c		\
	  src/get_next_line.c

OBJ = $(SRC:.c=.o)

INCLUDE = -Ilibft

FLAG = -Wextra -Wall -Werror

all : $(NAME)
	
OBJ : $(OBJ)
	gcc $(FLAG) -c $(SRC)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
clean : 
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
