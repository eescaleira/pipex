# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:09:41 by eescalei          #+#    #+#              #
#    Updated: 2023/12/28 18:27:10 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

C = cc -Wall -Wextra -Werror

SRC = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

HEADER = get_next_line_bonus.h
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs ${NAME} ${OBJS} ${HEADER}
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
.SILENT: