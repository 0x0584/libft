NAME = libft.a

SRCS := $(wildcard *.c)
DEPS := $(wildcard *.h)
OBJS := $(addsuffix .o, $(basename $(SRCS)))

CC = gcc
CFLAGS += -Wall -Werror -Wextra
LDFLAGS += -I.

RM = rm -f

all: $(NAME)
	@echo "done."

$(NAME): $(OBJS)
	ar rc -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
