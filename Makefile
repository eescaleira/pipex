# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 07:48:01 by eescalei          #+#    #+#              #
#    Updated: 2024/01/29 19:31:44 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc #-Wall -Wextra -Werror
LIB_PATH = ./inc/my_library/

SRC = src/pipex.c \
		src/processes.c \
		src/ft_split.c \
		src/free_errors.c

SRC_BONUS = src_bonus/pipex.c \
				src_bonus/processes.c \
				src_bonus/ft_split.c \
				src_bonus/free_errors.c \
				src_bonus/manage_info.c

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all:	${NAME} 

${NAME}:	${OBJ}
	make -C ./inc/my_library/
	${CC} ${OBJ} ./inc/my_library/get_next_line/get_next_line.a ./inc/my_library/ft_printf/libftprintf.a ./inc/my_library/libft/libft.a -o ${NAME}

bonus:	${OBJ_BONUS}
	make -C ./inc/my_library/
	${CC} ${OBJ_BONUS} ./inc/my_library/get_next_line/get_next_line.a ./inc/my_library/ft_printf/libftprintf.a ./inc/my_library/libft/libft.a -o ${NAME}

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make fclean -C ${LIB_PATH}

fclean: clean
	rm -f $(NAME)

re: fclean all
#.SILENT: