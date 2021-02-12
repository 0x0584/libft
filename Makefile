#******************************************************************************#
#																			   #
#														  :::	   ::::::::	   #
#	 Makefile											:+:		 :+:	:+:	   #
#													  +:+ +:+		  +:+	   #
#	 By: archid- <marvin@42.fr>						+#+	 +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2019/03/30 17:28:04 by archid-		   #+#	  #+#			   #
#    Updated: 2021/02/11 15:24:00 by archid-          ###   ########.fr        #
#																			   #
#******************************************************************************#

DEBUG	?= 0

NAME	= libft.a
RM		= rm -rf

DEPS	= $(shell find . -type f -name '*.h' | cut -c 3-)
SRCS	= $(shell find . -type f -name "*.c" | cut -c 3-)
OBJDIR	= .obj
OBJS	:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

CC		= gcc

YLW		= \033[0;33m[o]\033[0m

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Og
else
	CFLAGS = -O3 -Werror
endif
CFLAGS	+= -Wall -Wextra -Wpedantic -I.

all: flags $(NAME)

flags:
	@echo
	@printf "\033[0;35mCC\033[0m     = $(CC)\n"
	@printf "\033[0;35mCFLAGS\033[0m = $(CFLAGS)\n"
	@echo

$(NAME): $(OBJS)
	@rm -rf $(NAME)
	@ar rc $(NAME) $^
	@printf "\n$(YLW) archived $(NAME).\n"

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p  $(@D)
	@printf "compiling $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: setup all clean fclean re
