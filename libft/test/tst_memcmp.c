/*
 * File: tst_memcmp.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-18 Mon 03:24:27>
 * Updated: <2019-02-21 Thu 17:10:29>
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
	int *array, *test;
	int i = 0, size;

	srand(time(NULL));
	size = (argc == 1) ? 0xff : (argc - 1);
	array = malloc(size * sizeof(int));
	test = malloc(size * sizeof(int));
	while (i < size) {
		array[i] = (argc == 1) ? i : ft_atoi(argv[i + 1]);
		test[i] = rand() % 0xff;
		i++;
	}
	print_array_of_ints(test, size);
	printf(" ('%d' vs '%d')", memcmp(array, test, size),
		   ft_memcmp(array, test, size));
	free(array);
	free(test);
	return 0;
}
