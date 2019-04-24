all: libft
	gcc -Wall -Werror -Wextra -g3 get_next_line.{c,h} libft/libft.a

libft:
	make -C ./libft/

test: all
# ./a.out test.txt > out.txt
	./a.out test.txt && echo "---------------" && cat test.txt
clean:
	rm -rf a.out* get_next_line.h.gch

# make && ./a.out test.txt && echo "---------------" && cat test.txt
