/*
 * File: ft_lstdeli.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 18:20:36>
 * Updated: <2019-02-21 Thu 18:35:46>
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

t_bool ft_lstdeli(t_list ** lst, void (*f) (void *, size_t),
				  unsigned int index) {
	t_list *tmp;
	t_list *prev;
	unsigned int i;

	i = 0;
	tmp = *lst;
	while (tmp && i++ < index) {
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL && i < index)
		return false;
	else if (prev != NULL)
		prev->next = tmp->next;
	else
		*lst = tmp->next;
	ft_lstdelone(&tmp, f);

	return true;
}
