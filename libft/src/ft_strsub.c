/*
 * File: ft_strsub.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-11 Mon 01:22:18>
 * Updated: <2019-02-11 Mon 01:54:32>
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

char *ft_strsub(char const *s, unsigned int start, size_t len) {
	char *buff;
	t_uint i;

	buff = ft_memalloc(len + 1);
	if (buff == NULL)
		return (NULL);
	i = start;
	buff[len] = '\0';
	while (i < start + len) {
		buff[i - start] = s[i];
		i++;
	}
	return (buff);
}
