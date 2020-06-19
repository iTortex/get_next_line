SRC = get_next_line.c get_next_line_utils.c
OBJ = get_next_line_utils.o get_next_line.o
NAME = get_next_line

all: $(NAME)

$(NAME):
		clang -Wall -Wextra -Werror -g get_next_line.c get_next_line_utils.c

clean:
	/bin/rm -f get_next_line_utils.o get_next_line.o

fclean: clean
	/bin/rm -f a.out
	
re: fclean all

.PHONY: all clean fclean re bonus