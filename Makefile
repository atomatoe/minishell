NAME = minishell
HEADERS = ./cub/minishell.h
CFLAGS = -Wall -Werror -Wextra

SRC = main.c parser/wait_str.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	gcc $(OBJ) $(CFLAGS) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean:	clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re:		fclean all

bonus: all

norm: 
	norminette parser/*.c libft/*.c main.c

.PHONY: all clean fclean re bonus norm