/*
 * File: ft_atoi.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-10 Sun 20:17:17>
 * Updated: <2019-02-11 Mon 22:34:46>
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

int ft_atoi(const char *nptr) {
	int nbr;
	int len;
	int sign;
	int i;

	if (nptr == NULL)
		return 0;
	while (*nptr <= ' ')
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		sign = *nptr++ == '-' ? (-1) : (1);
	len = 0;
	while (nptr[len] && ft_isdigit(nptr[len]))
		len++;
	i = -1;
	nbr = 0;
	while (++i < len) {
		if (!ft_isdigit(nptr[i]))
			return (nbr * sign * ft_power(10, len - i));
		nbr += ft_power(10, len - i - 1) * (nptr[i] - '0');
	}
	return (nbr * sign);
}
