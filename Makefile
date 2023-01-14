#******************************************************************************#
#																			   #
#														  :::	   ::::::::	   #
#	 Makefile											:+:		 :+:	:+:	   #
#													  +:+ +:+		  +:+	   #
#	 By: archid- <marvin@42.fr>						+#+	 +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2019/03/30 17:28:04 by archid-		   #+#	  #+#			   #
#    Updated: 2023/01/15 03:19:26 by archid-          ###   ########.fr        #
#																			   #
#******************************************************************************#

DEBUG	?= 0
COLORED	?= 0

NAME	= libft
STATIC_LIB = $(NAME).a
SHARED_LIB = $(NAME).so

SHARED_LIBFT ?= 1

RM		= rm -rf

DEPS	= $(shell find . -type f -name '*.h' | cut -c 3-)
SRCS	= $(shell find . -type f -name "*.c" | cut -c 3-)
OBJDIR	= .obj
OBJS	:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

CC		= clang

ifeq ($(COLORED),1)
    YLW		= \033[0;33m[o]\033[0m
    MGNT    = \033[0;35m
    RESET   = \033[0m
endif

ifeq ($(DEBUG),1)
	CFLAGS = -g -Og
else
	CFLAGS = -O3 -Werror
endif

CFLAGS	+= -Wall -Wextra -Wpedantic -I.
ifeq ($(SHARED_LIBFT),1)
	CFLAGS += -fPIC
endif

all: flags $(NAME)

flags:
	@echo
	@printf "$(MGNT)CC$(RESET)     = $(CC)\n"
	@printf "$(MGNT)CFLAGS$(RESET) = $(CFLAGS)\n"
	@echo

$(NAME): $(OBJS)
ifeq ($(SHARED_LIBFT),1)
	@$(RM) $(SHARED_LIB)
	$(CC) $(CFLAGS) -shared -o $(SHARED_LIB) $^
else
	@$(RM) $(STATIC_LIB)
	ar rc $(STATIC_LIB) $^
endif

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p  $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJDIR)
ifeq ($(SHARED_LIBFT),1)
	@$(RM) $(SHARED_LIB)
else
	@$(RM) $(STATIC_LIB)
endif

re: fclean all

.PHONY: setup all clean fclean re
