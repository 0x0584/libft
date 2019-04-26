TST_DIR = tests
INPUT	= $(TST_DIR)/BASIC_TEST
OUTPUT	= out.txt
BAR		= echo "\n---------------\n" $(INPUT)

all: libft
# gcc -Wall -Werror -Wextra -g3 get_next_line.{c,h} libft/libft.a
	gcc -Wall -Wextra -g3 get_next_line.{c,h} libft/libft.a

libft:
	make -C ./libft/

test: all
# ./a.out test.txt > out.txt
	./a.out $(INPUT) && $(BAR) && cat $(INPUT)

diff: all
	./a.out $(INPUT) > $(OUTPUT) && diff -u $(INPUT) $(OUTPUT) | colordiff

clean:
	rm -rf a.out* get_next_line.h.gch

# make && ./a.out test.txt && echo "---------------" && cat test.txt
