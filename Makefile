#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 23:13:45 by archid-           #+#    #+#              #
#    Updated: 2019/11/26 18:00:36 by archid-          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ARGS		= 1 5 4 2 7 3 8
CORE_SRCS 	= src/op.c src/ps.c src/reader.c src/ops.c src/bs.c
PUSH_SWAP	= src/push_swap.c
CHECKER 	= src/checker.c

CFLAGS		= -g -Wall -Wextra
LDFLAGS 	= -Iinclude -Ilibft -Llibft -lft

all:
	@make -C libft
	gcc $(CFLAGS) $(CORE_SRCS) $(PUSH_SWAP) -o push_swap $(LDFLAGS)
	gcc $(CFLAGS) $(CORE_SRCS) $(CHECKER) -o checker $(LDFLAGS)

it: all
	./checker $(ARGS) < ./push_swap $(ARGS)

.PHONY: all it
