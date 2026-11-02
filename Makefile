NAME = my_readline
SRC = main.c my_readline.c functions.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ)
	gcc $(CFLAGS) &(OBJ) -o $(NAME)
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re