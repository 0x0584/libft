/*
 * File: ft_putbase.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 16:38:32>
 * Updated: <2019-02-21 Thu 17:41:36>
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

void _putbase(unsigned long in, char *base) {
	unsigned long len;

	len = ft_strlen(base);
	if (in > len)
		_putbase(in / len, base);
	ft_putchar(base[in % len]);
}

void ft_putbase(long in, char *base) {
	unsigned long ul;

	ul = in;
	if (in < 0) {
		ul = -in;
		ft_putchar('-');
	}
	_putbase(ul, base);
}
