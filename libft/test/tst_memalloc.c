/*
 * File: tst_memalloc.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-17 Sun 03:17:56>
 * Updated: <2019-02-17 Sun 03:40:45>
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
#include "testing.h"

int main(int argc, char *argv[]) {
	int i = 0;
	void *tmp;

	if (argc == 1)
		return 0;

	while (i < argc) {
		tmp = ft_memalloc(abs(atoi(argv[i])));
		free(tmp);
		i++;
	}
	return 0;
}