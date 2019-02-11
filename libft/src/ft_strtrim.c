/*
 * File: ft_strtrim.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-11 Mon 01:52:33>
 * Updated: <2019-02-11 Mon 02:40:32>
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

char *ft_strtrim(char const *s) {
	char *buff;
	size_t len;
	size_t last;
	size_t i;

	while (*s <= ' ' && *s)
		s++;
	last = 0;
	len = ft_strlen(s);
	if (len != 0)
		while (s[len - last - 1] <= ' ')
			last++;
	buff = ft_memalloc(len - last + 1);
	buff[len - last] = '\0';
	i = 0;
	while (i < len - last) {
		buff[i] = s[i];
		i++;
	}
	return (buff);
}
