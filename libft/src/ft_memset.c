/*
 * File: ft_memset.c
 * Author: Anas Rchid
 *
 * Created: <2019-02-06 Wed 21:25:36>
 * Updated: <2019-02-11 Mon 22:48:52>
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

void *ft_memset(void *mem, int c, size_t n) {
	t_uchar *buff;
	size_t i;

	i = 0;
	buff = (t_uchar *) mem;
	while (i < n)
		buff[i++] = (t_uchar) c;
	return mem;
}
