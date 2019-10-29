#******************************************************************************#
#																			   #
#														  :::	   ::::::::	   #
#	 Makefile											:+:		 :+:	:+:	   #
#													  +:+ +:+		  +:+	   #
#	 By: archid- <marvin@42.fr>						+#+	 +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2019/03/30 17:28:04 by archid-		   #+#	  #+#			   #
#    Updated: 2019/10/29 18:57:55 by archid-          ###   ########.fr        #
#																			   #
#******************************************************************************#

DEBUG	= 1

NAME	= libft.a
RM		= rm -f

DEPS	= $(shell find . -type f -name '*.h' | cut -c 3-)
SRCS	= $(shell find . -type f -name "*.c" | cut -c 3-)
OBJDIR	= obj
OBJS	= $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra

YLW		= \033[0;33m[o]\033[0m

ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb
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
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@$(RM) $(notdir $(OBJS))

fclean:
	@$(RM) $(notdir $(OBJS))
	@$(RM) $(NAME)

re: fclean all
