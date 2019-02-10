/*
 * File: ft_strlcat.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-10 Sun 16:51:52>
 * Updated: <2019-02-10 Sun 17:02:15>
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

char *ft_strlcat(char *dest, const char *src, size_t n) {
	size_t dlen;
	size_t slen;
	size_t size;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	size = n < dlen ? slen + n : slen + dlen;
	return ft_strncat(dest, src, size);
}
