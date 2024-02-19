NAME = push_swap

SRCS =	src/main.c\
		src/sort.c\
		src/simple.c\
		src/checks.c\
		src/index.c\
		src/listoperations.c\
		src/stackoperations.c\
		src/utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -s -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "Program ready!"

clean: 
	@${MAKE} -s -C ./libft fclean
	@${RM} ${OBJS}
	@echo "Program cleaned successfully!"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re