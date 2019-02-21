/*
 * File: tst_lstadd.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-16 Sat 04:14:01>
 * Updated: <2019-02-21 Thu 17:24:42>
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
	int i = 2;

	printf("'%d", atoi(argv[1]));
	while (i < argc)
		printf(" %d", atoi(argv[i++]));
	printf("' ");
	head = int_lst_from_args(argc, argv);
	ft_lstdump(head, dump_as_int);
	ft_lstdel(&head, del);

	return 0;
}
