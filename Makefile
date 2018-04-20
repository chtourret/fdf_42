# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctourret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 14:07:06 by ctourret          #+#    #+#              #
#    Updated: 2017/04/13 14:50:22 by ctourret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re

NAME = fdf

CC = gcc

LDFLAGS = -Wall -Wextra -Werror 

LDLIBC = -L libft/ -lft

LDMINI = -L minilibx_macos/ -lmlx -framework OpenGl -framework AppKit

SRC = src/draw.c\
	  src/hook.c\
	  src/rot.c\
	  src/parse.c\
	  src/tools.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

OBJ : $(OBJ)
	$(CC) $(LDFLAGS) -c $(SRC)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx_macos
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBC) $(LDMINI) -o $(NAME)

clean :
	make clean -C libft
	make clean -C minilibx_macos
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
