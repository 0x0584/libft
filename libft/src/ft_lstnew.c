/*
 * File: ft_lstnew.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-15 Fri 04:28:18>
 * Updated: <2019-02-16 Sat 04:09:30>
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

t_list * ft_lstnew(void const *content, size_t content_size) {
	t_list *lst;

	lst = (t_list *) ft_memalloc(sizeof *lst);
	if (lst == NULL)
		return NULL;
	if (content == NULL)
		lst->content = NULL;
	else {
		lst->content = ft_memalloc(content_size);
		ft_memmove(lst->content, content, content_size);
	}
	lst->content_size = (content == NULL) ? 0 : content_size;
	lst->next = NULL;

	return lst;
}
