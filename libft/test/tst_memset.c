/*
 * File: tst_memset.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-08 Fri 23:20:41>
 * Updated: <2019-02-10 Sun 01:40:38>
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
	size_t *array, size, i = 0;
	int value;

	size = (argc != 3) ? 0xff : atol(argv[1]);
	value = (argc != 3) ? 0x00 : atoi(argv[2]);
	array = malloc(size * sizeof *array);
	while (i < size) {
		array[i] = i;
		i++;
	}
	print_array(array, size);
	ft_memset(array, value, size * sizeof *array);
	print_array(array, size);
	free(array);
	return 0;
}
