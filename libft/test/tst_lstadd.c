/*
 * File: tst_lstadd.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-16 Sat 04:14:01>
 * Updated: <2019-02-19 Tue 01:38:44>
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

#include "libft.h"

void del(void *v, size_t sz) {
	/* int * mtp = v; */

	/* printf("\n>> %d <<\n", *mtp); */
	free(v);
	if (sz) {
		/* just to avoid compilation warnings */
	}
}

int main() {
	int foo = 9;
	int bar = 8;
	int baz = 7;
	int fuzz = 75;
	int buzz = 88;

	t_list *head = ft_lstnew(&foo, sizeof(int));
	ft_lstadd(&head, ft_lstnew(&bar, sizeof(int)));
	ft_lstadd(&head->next, ft_lstnew(&baz, sizeof(int)));
	ft_lstadd(&head->next->next, ft_lstnew(&fuzz, sizeof(int)));
	ft_lstadd(&head->next->next->next, ft_lstnew(&buzz, sizeof(int)));

	/*
	 * TODO: create tests and update runtest.pl
	 *
	 * 1) create tests for lst
	 * 2) create tests for strings
	 * 3) update runtest.pl run all the tests
	 *	  with some random input in each of tst_*.pl
	 *
	 * This should be done by tomorrow!
	 */

	ft_lstdel(&head, del);
	return 0;
}
