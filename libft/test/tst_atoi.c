/*
 * File: tst_atoi.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-12 Tue 01:54:27>
 * Updated: <2019-02-13 Wed 23:15:38>
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
	size_t size, i = 0;
	char *nbr_as_str;

	size = (argc == 1) ? 1 : argc - 1;
	array = malloc(size * sizeof(int));
	test = malloc(size * sizeof(int));
	while (i < size) {
		nbr_as_str = argc == 1 ? "-2147483648" : argv[i + 1];
		array[i] = ft_atoi(nbr_as_str);
		test[i] = atoi(nbr_as_str);
		i++;
	}
	i = 1;
	printf("'%s", argv[1]);
	while (i < size)
		printf(" %s", argv[i++]);
	putchar('\'');
	print_test_of_ints(array, test, size);
	free(array); free(test);
	return 0;
}
