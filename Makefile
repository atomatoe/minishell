NAME = minishell
HEADERS = ./cub/minishell.h
CFLAGS = -Wall -Werror -Wextra

SRC = main.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	$(MAKE) -C parser all
	gcc $(OBJ) $(CFLAGS) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C parser clean

fclean:	clean
	$(MAKE) -C libft fclean
	$(MAKE) -C parser fclean
	rm -f $(NAME)

re:		fclean all

bonus: all

norm: 
	norminette parser/*.c libft/*.c main.c

.PHONY: all clean fclean re bonus norm