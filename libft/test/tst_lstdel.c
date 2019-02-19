/*
 * File: tst_lstdel.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-16 Sat 12:48:15>
 * Updated: <2019-02-19 Tue 01:36:58>
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

/* FIXME: memory is not free'd or what!? */

#include "libft.h"
#include "testing.h"

void del(void *v, size_t sz) {
	/* int * mtp = v; */

	/* printf("\n>> %d <<\n", *mtp); */
	free(v);
	if (sz) {
		/* just to avoid compilation warnings */
	}
}

int *atoi_dup(char *str) {
	int *foo = malloc(sizeof(int));
	*foo = atoi(str);
	return foo;
}

int main(int argc, char *argv[]) {
	t_list *head, *tmp;
	int i = 2, *foo;

	if (argc == 1)
		return 0;

	printf("'%d", atoi(argv[1]));
	while (i < argc)
		printf(" %d", atoi(argv[i++]));
	printf("' vs '");
	i = 2;
	head = ft_lstnew(atoi_dup(argv[1]), sizeof(int));
	tmp = head;
	foo = (tmp->content);
	printf("%d", *foo);
	while (i < argc) {
		tmp->next = ft_lstnew(atoi_dup(argv[i]), sizeof(int));
		foo = (tmp->next->content);
		printf(" %d", *foo);
		tmp = tmp->next;
		i++;
	}
	printf("'");
	ft_lstdel(&head, del);

	return 0;
}
