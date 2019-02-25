/*
 * File: testing.h
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-09 Sat 00:07:30>
 * Updated: <2019-02-25 Mon 20:58:20>
 *
 * Copyright (C) 2019
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.	If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */

#ifndef TESTING_H
#  define TESTING_H

#  include <stdlib.h>
#  include <stdio.h>
#  include <string.h>
#  include <ctype.h>
#  include <time.h>

#  include "libft.h"

void replace_me(void);
void print_array_of_ints(int *array, size_t size);
void print_test_of_ints(int *array, int *test, size_t size);
void print_words(char **words);
void free_words(char **words);
void del(void *v, size_t sz);
int *atoi_dup(char *str);
t_list *int_lst_from_args(int argc, char **argv);
void dump_as_int(size_t pos, t_list * elem);

void replace_me(void) {
	printf("'args' ('output' vs 'expected output')");
}

void print_array_of_ints(int *array, size_t size) {
	size_t i = 0;

	printf("'%d", array[i++]);
	while (i < size)
		printf(" %d", array[i++]);
	putchar('\'');
}

void print_test_of_ints(int *array, int *test, size_t size) {
	printf("%s", " (");
	print_array_of_ints(array, size);
	printf("%s", " vs ");
	print_array_of_ints(test, size);
	putchar(')');
}

void print_words(char **words) {
	int i = 0;
	while (words[i])
		printf("%s\n", words[i++]);
}

void free_words(char **words) {
	int i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

void del(void *v, size_t sz) {
	if (sz || 1)
		free(v);
}

int *atoi_dup(char *str) {
	int *foo = malloc(sizeof(int));
	*foo = atoi(str);
	return foo;
}

t_list *int_lst_from_args(int argc, char **argv) {
	t_list *head = NULL;
	int i = 1, *bar;

	if (argc == 1)
		return head;

	while (i < argc) {
		bar = atoi_dup(argv[i]);
		if (head == NULL)
			head = ft_lstnew(bar, sizeof(int));
		else
			ft_lstadd(&head, ft_lstnew(bar, sizeof(int)));
		free(bar);
		i++;
	}
	return head;
}

void dump_as_int(size_t pos, t_list * elem) {
	int *foo = elem->content;
	printf("%s%d%s", (pos == 0) ? "[" : "", *foo,
		   elem->next ? " -> " : "]");
}

#endif				/* TESTING_H */
