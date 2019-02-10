/*
 * File: ft_strchr.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-10 Sun 17:03:53>
 * Updated: <2019-02-10 Sun 18:53:13>
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

char *ft_strchr(const char *str, int c) {
	char *buff;

	buff = (char *) str;
	while (*buff) {
		if (*buff == (char) c)
			return (buff);
		buff++;
	}
	if (*buff == (char) c)
		return (buff);
	return (NULL);
}
