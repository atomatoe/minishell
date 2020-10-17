NAME = minishell
HEADERS = ./parser/parser.h
CFLAGS = -Wall -Werror -Wextra

SRC = main.c parser/wait_str.c parser/cut_line.c parser/get_data.c\
	parser/split_for_mini.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	gcc $(OBJ) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

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