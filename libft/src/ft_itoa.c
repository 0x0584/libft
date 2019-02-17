/*
 * File: ft_itoa.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-15 Fri 01:52:54>
 * Updated: <2019-02-17 Sun 03:11:23>
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

/* TODO: discover why the previous version was not working */

void _base_10(t_uint nbr, char *str, t_uint i, t_uint * size) {
	if (nbr >= 10)
		_base_10(nbr / 10, str, i + 1, size);
	str[i] = nbr % 10 + '0';
	if (nbr / 10 == 0)
		str[*size = i + 1] = '\0';
}

char *ft_itoa(int nbr) {
	t_uint u_nbr;
	t_uint size;
	char buff[0xff];
	char *str;

	u_nbr = (nbr < 0) ? -nbr : nbr;
	_base_10(u_nbr, buff, 0, &size);
	str = (char *) ft_memalloc(size + (nbr < 0) + 1);
	if (str == NULL)
		return NULL;
	else if (nbr < 0)
		str[0] = '-';
	char *s = ft_strnrev(buff, 0, size);
	ft_strcpy(str + (nbr < 0), s);
	return str;
}
