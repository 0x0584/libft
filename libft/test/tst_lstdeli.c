/*
 * File: tst_lstdeli.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 18:43:08>
 * Updated: <2019-02-21 Thu 18:51:16>
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

int main(int argc, char *argv[]) {
	t_list *head;

	if (argc <= 3)
		return 0;

	head = int_lst_from_args(argc - 1 , argv + 1);
	ft_lstdump(head, dump_as_int);
	printf(" ");
	ft_lstdeli(&head, del, atoi(argv[1]));
	ft_lstdump(head, dump_as_int);
	ft_lstdel(&head, del);
	return 0;
}
