/*
 * File: ft_putnbr_fd.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-12 Tue 00:40:27>
 * Updated: <2019-02-12 Tue 00:47:25>
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

void ft_putnbr_fd(int n, int fd) {
	t_uint u;

	if (n < 0)
		ft_putchar_fd('-', fd);
	u = (n < 0) ? -n : n;
	if (u >= 10)
		ft_putnbr_fd(u / 10, fd);
	ft_putchar_fd(u % 10 + '0', fd);
}
