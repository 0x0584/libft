#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 23:13:45 by archid-           #+#    #+#              #
#    Updated: 2019/11/27 11:12:30 by archid-          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FTDIR		= libft
SRCDIR		= src
DEPSDIR		= include
COREDIR		= $(SRCDIR)/core

CORESRCS 	= $(shell find $(COREDIR) -name '*.c' -type f)
COREOBJS	= $(patsubst $(COREDIR)/%.c, $(COREDIR)/%.o, $(CORESRCS))

PUSH_SWAP	= $(SRCDIR)/push_swap.c
CHECKER 	= $(SRCDIR)/checker.c

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDFT		= -L$(FTDIR) -lft
DEPS		= -I$(DEPSDIR) -I$(FTDIR)

MIN			= -1000
MAX			= 1000
N_ELEMS		= 100

all: init push_swap checker

push_swap: init
	@$(CC) $(CFLAGS) $(COREOBJS) $(PUSH_SWAP) -o push_swap $(DEPS) $(LDFT)

checker: init
	@$(CC) $(CFLAGS) $(COREOBJS) $(CHECKER) -o checker $(DEPS) $(LDFT)

init: $(COREOBJS)
	@make -C $(FTDIR)

$(COREDIR)/%.o: $(COREDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(DEPS)

clean:
	@make -C $(FTDIR) clean
	$(shell find $(COREDIR) -name '*.o' -type f -delete)

fclean:
	@make -C $(FTDIR) fclean
	$(shell find $(COREDIR) -name '*.o' -type f -delete)
	@rm -rf push_swap* checker*

re: fclean all

gen:
	@ruby -e "puts ($(MIN)..$(MAX)).to_a.shuffle.take($(N_ELEMS)).join(' ')"

.PHONY: all clean init push_swap checker gen
