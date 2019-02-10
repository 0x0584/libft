# File: Makefile
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-08 Fri 22:26:56>
# Updated: <2019-02-10 Sun 01:31:02>
#
# Copyright (C) 2019
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.	If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth
# Floor, Boston, MA 02110-1301, USA.

LIBFT = libft.a

SRCS_DIR = src
DEPS_DIR = include
OBJS_DIR = bin
TEST_DIR = test

SRCS := $(shell find $(SRCS_DIR) -name '*.c')
DEPS := $(shell find $(DEPS_DIR) -name '*.h')
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS += -Wall -Werror -Wextra
LDFLAGS += -I $(DEPS_DIR)

RM = rm -f

all: $(LIBFT)
	@echo "done."

$(LIBFT): build-dir $(OBJS)
	ar rc -o $(LIBFT) $(OBJS)

build-dir:
	@echo "building objects.."
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	@echo "cleaning.."
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT) $(TEST_DIR)/$(LIBFT)

re: fclean all

test: re
	@cp $(LIBFT) test/$(LIBFT)
	@make -C $(TEST_DIR)
