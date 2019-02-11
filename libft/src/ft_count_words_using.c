/*
 * File: ft_count_words_using.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-11 Mon 18:11:08>
 * Updated: <2019-02-11 Mon 18:57:51>
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

t_uint ft_count_words_using(char const *s, char c) {
	t_uint count;

	count = 0;
	while (*s) {
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break;
		while (*s && *s != c)
			s++;
		count++;
	}
	return (count);
}
