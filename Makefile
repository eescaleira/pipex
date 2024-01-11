# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 07:48:01 by eescalei          #+#    #+#              #
#    Updated: 2024/01/11 22:18:37 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc -Wall -Wextra -Werror
LIB_PATH = ./inc/my_library/

SRC = src/pipex.c

OBJ = ${SRC:.c=.o}

all:	${NAME}

${NAME}:	${OBJ}
	make -C ${LIB_PATH}
	${CC} ${LIB_PATH}get_next_line/get_next_line.a ${LIB_PATH}ft_printf/libftprintf.a ${LIB_PATH}libft/libft.a ${OBJ} -o ${NAME}

clean:
	rm -f $(OBJ)
	make fclean -C ${LIB_PATH}

fclean: clean
	rm -f $(NAME)

re: fclean all
.SILENT: