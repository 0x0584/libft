all:
	gcc -Wall -Werror -Wextra -g3 get_next_line.{c,h} libft/libft.a

test: all
	./a.out test.txt
