NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes -g

SRCS =	src/main.c\
		src/sort.c\
		src/simple.c\
		src/checks.c\
		src/index.c\
		src/listoperations.c\
		src/listdelete.c\
		src/utils.c\
		src/frees.c\
		src/push.c\
		src/swap.c\
		src/rotate.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Program ready!"

clean: 
	@$(MAKE) -s -C ./libft fclean
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re