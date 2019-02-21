/*
 * File: ft_lstmap.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-16 Sat 02:22:19>
 * Updated: <2019-02-21 Thu 21:08:34>
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

t_list *ft_lstmap(t_list * lst, t_list * (*f) (t_list * elem)) {
	t_list *head;
	t_list *tmp;

	head = NULL;
	if (lst && f) {
		tmp = lst;
		while (tmp) {
			if (head == NULL)
				head = f(tmp);
			else
				ft_lstadd(&head, f(tmp));
			tmp = tmp->next;
		}
	}
	ft_lstrev(&head);
	return head;
}
