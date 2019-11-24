#******************************************************************************#
#																			   #
#														  :::	   ::::::::	   #
#	 Makefile											:+:		 :+:	:+:	   #
#													  +:+ +:+		  +:+	   #
#	 By: archid- <marvin@42.fr>						+#+	 +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2019/03/30 17:28:04 by archid-		   #+#	  #+#			   #
#    Updated: 2019/11/24 20:22:44 by archid-          ###   ########.fr        #
#																			   #
#******************************************************************************#

DEBUG	= 1

NAME	= libft.a
RM		= rm -f

DEPS	= $(shell find . -type f -name '*.h' | cut -c 3-)
SRCS	= $(shell find . -type f -name "*.c" | cut -c 3-)
OBJDIR	= obj
OBJS	:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra

YLW		= \033[0;33m[o]\033[0m

ifeq ($(DEBUG), 1)
	CFLAGS += -g
else
	CFLAGS += -Werror
endif

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YLW) archiving $(NAME)..\n"
	@rm -rf $(NAME)
	@ar rc $(NAME) $^
$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p  $(@D)
#	@printf "compiling $<\n"
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@$(RM) $(shell find $(OBJDIR) -name '*.o')

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: setup all clean fclean re
