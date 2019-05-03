# File: Makefile
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-08 Fri 22:26:56>
#    Updated: 2019/05/03 04:45:50 by archid-          ###   ########.fr        #
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
	@if [ ! -f $(TEST_DIR)/$(LIBFT) ]; then \
		cd $(TEST_DIR);						\
		ln -s ../$(LIBFT) $(LIBFT);			\
	fi
	@if [ ! -f $(TEST_DIR)/$(notdir $(DEPS)) ]; then \
		cd $(TEST_DIR);								 \
		ln -s ../$(DEPS) $(notdir $(DEPS));			 \
	fi
	@make -C $(TEST_DIR)

$(LIBFT): build-dir $(OBJS)
	@ar rc $(LIBFT) $(OBJS)

build-dir:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT) $(TEST_DIR)/$(LIBFT)

re: fclean all test

# This would work only if there's one and only one header!
# Otheriwse, copying/linking other headers manually is required
#
# Update: done in all instead of test
# test: $(DEPS)
#	@if [ ! -f $(TEST_DIR)/$(LIBFT) ]; then \
#		cd $(TEST_DIR); \
#		ln -s ../$(LIBFT) $(LIBFT); \
#	fi
#	@if [ ! -f $(TEST_DIR)/$(notdir $(DEPS)) ]; then \
#		cd $(TEST_DIR); \
#		ln -s ../$(DEPS) $(notdir $(DEPS)); \
#	fi
#	@make -C $(TEST_DIR)
