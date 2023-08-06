#ASCII

_END		= 	\033[0m
_BOLD		= 	\e[1m
_UNDER		= 	\e[4m
_BLINK		= 	\e[5m
_FASTBLINK	= 	\e[6m
_REV		= 	\e[7m

_BLACK		=	\e[1;30m	#BLACK IN BOLD
_RED		=	\e[31m	#NORMAL RED
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_WHITE		=	\e[1;37m


_ERASE 		=	\e[2k\r


NAME = pipex
CC = cc
FLAGS = -Wall -Werror -Wextra
INCLUDE =	-I ./inc/ \
			-I ./libft/


SRC_PATH = ./src/
OBJ_PATH = ./obj/

LIB_PATH = ./libft
LIB_NAME = /libft.a
LIB = $(LIB_PATH)$(LIB_NAME) #./libft/libft.a

RM = rm -rf

SOURCES = 	pipex.c \
			childs.c \
			free.c


#addprfix (adds in the back) and there is the addsufix (adds in the front)

SRCS = $(addprefix $(SRC_PATH), $(SOURCES))
OBJ = $(SOURCES:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))




all:	$(LIB) ${NAME}

$(LIB):
		make -sC $(LIB_PATH)

${NAME}:	${OBJS}
		printf "$(_ERASE)$(_GREEN)All files compiled into '$(OBJ_PATH)'\n$(_END)"
		${CC} ${FLAGS} -o $(NAME) $(OBJS) $(LIB) ${INCLUDE}
		printf "$(_ERASE)$(_GREEN)Executable '$(NAME)' created \n$(_END)"


$(OBJS):	| $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				printf "$(_ERASE)$(_YELLOW)Compiling $< $(_END)"
				$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_PATH):
		mkdir $(OBJ_PATH)

clean:
	${RM} ${OBJ_PATH}
	make -sC $(LIB_PATH) clean

fclean:	clean
		${RM} ${NAME}
		make -sC $(LIB_PATH) fclean

re:	fclean all

.SILENT:
.PHONY:	all clean fclean re
