/*
 * File: ft_strncat.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-10 Sun 16:23:33>
 * Updated: <2019-02-10 Sun 16:51:03>
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

char *ft_strncat(char *dest, const char *src, size_t n) {
	size_t i;

	i = 0;
	while (*dest)
		dest++;
	while (src[i] && i < n) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
