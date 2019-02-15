/*
 * File: ft_itoa.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-15 Fri 01:52:54>
 * Updated: <2019-02-15 Fri 04:21:25>
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

void _convert_base_10(t_uint nbr, char *str_nbr, t_uint index) {
	if (nbr >= 10)
		_convert_base_10(nbr / 10, str_nbr, index + 1);
	str_nbr[index] = nbr % 10 + '0';
	if (nbr / 10 == 0)
		str_nbr[index + 1] = '\0';
}

char *ft_itoa(int nbr) {
	t_uint u_nbr;
	char buff[0xff];
	char *str_nbr;

	u_nbr = (nbr < 0) ? -nbr : nbr;
	_convert_base_10(u_nbr, buff, 0);
	str_nbr = (char *) ft_memalloc(ft_strlen(buff) + (nbr < 0) + 1);
	if (str_nbr == NULL)
		return NULL;
	else if (nbr < 0)
		str_nbr[0] = '-';
	return ft_strcpy(str_nbr + (nbr < 0), ft_strrev(buff));
}
