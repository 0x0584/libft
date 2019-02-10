/*
 * File: ft_memcmp.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-08 Fri 22:44:57>
 * Updated: <2019-02-10 Sun 00:42:49>
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

int ft_memcmp(const void *s1, const void *s2, size_t n) {
	t_uchar *foo;
	t_uchar *bar;
	size_t i;

	i = 0;
	foo = (t_uchar *) s1;
	bar = (t_uchar *) s2;
	while (i < n) {
		if (foo[i] != bar[i])
			break;
		i++;
	}
	return (foo[i] - bar[i]);
}
