/*
 * File: ft_strnrev.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-17 Sun 02:23:26>
 * Updated: <2019-02-17 Sun 02:33:21>
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

char *ft_strnrev(char *str, size_t start, size_t end) {
	size_t length;
	size_t i;
	char tmp;

	i = start;
	length = (end > start) ? end - start : 0;
	while (i <= length / 2) {
		tmp = str[i];
		str[i] = str[start + length - i - 1];
		str[start + length - i - 1] = tmp;
		i++;
	}
	return str;
}
