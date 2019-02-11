/*
 * File: ft_memchr.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-08 Fri 22:31:13>
 * Updated: <2019-02-11 Mon 22:45:57>
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

void *ft_memchr(const void *s, int c, size_t n) {
	t_uchar *buff;
	size_t i;

	i = 0;
	buff = (t_uchar *) s;
	while (i < n) {
		if (buff[i] == (t_uchar) c)
			return (void *) &buff[i];
		i++;
	}
	return NULL;
}
