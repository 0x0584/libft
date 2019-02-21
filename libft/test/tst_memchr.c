/*
 * File: tst_memchr.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-18 Mon 01:31:48>
 * Updated: <2019-02-21 Thu 17:13:52>
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
	int *array, *test, *test0;
	int i = 0, size;

	size = (argc <= 2) ? 0xff : (argc - 2);
	array = malloc(size * sizeof(int));
	while (i < size) {
		array[i] = (argc <= 2) ? i : ft_atoi(argv[i + 2]);
		i++;
	}
	print_array_of_ints(array, size);
	test = ft_memchr(array,
					 (argc <= 2) ? rand() % 0xff : ft_atoi(argv[1]),
					 size * sizeof(int));
	test0 = memchr(array,
				   (argc <= 2) ? rand() % 0xff : ft_atoi(argv[1]),
				   size * sizeof(int));
	print_test_of_ints(test0, test, size - (test - array));
	free(array);

	return 0;
}
