/*
 * File: ft_lstdump.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 16:30:55>
 * Updated: <2019-02-21 Thu 17:33:21>
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
#include <stdio.h>

void ft_lstdump(t_list * lst, void (*f) (size_t pos, t_list * elem)) {
	t_list *tmp;
	size_t index;

	index = 0;
	tmp = lst;
	while (tmp) {
		if (f != NULL)
			f(index++, tmp);
		else
			ft_putbase((long) tmp->content, HEXA_BASE);
		tmp = tmp->next;
	}
}
