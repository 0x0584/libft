/*
 * File: tst_lstmap.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-16 Sat 04:30:44>
 * Updated: <2019-02-21 Thu 19:43:02>
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
#include "testing.h"

t_list *add_one(t_list * elem) {
	int foo;
	int *s = elem->content;
	foo = *s + 1;

	return ft_lstnew(&foo, sizeof(int));
}

int main(int argc, char *argv[]) {
	t_list *head, *mapped;

	head = int_lst_from_args(argc, argv);
	ft_lstdump(head, dump_as_int);
	mapped = ft_lstmap(head, add_one);
	printf(" ");

	ft_lstdump(mapped, dump_as_int);
	ft_lstdel(&head, del);
	ft_lstdel(&mapped, del);
	return 0;
}
