/*
 * File: testing.h
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-09 Sat 00:07:30>
 * Updated: <2019-02-12 Tue 21:02:07>
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

#ifndef TESTING_H
#  define TESTING_H
#  include <stdlib.h>
#  include <stdio.h>
#  include <string.h>

void print_array_of_ints(int *array, size_t size);
void print_test_of_ints(int *array, int *test, size_t size);

void print_array_of_ints(int *array, size_t size) {
	size_t i = 0;

	printf("'%d", array[i++]);
	while (i < size)
		printf(" %d", array[i++]);
	putchar('\'');
}

void print_test_of_ints(int *array, int *test, size_t size) {
	printf("%s", " (");
	print_array_of_ints(array, size);
	printf("%s", " vs ");
	print_array_of_ints(test, size);
	putchar(')');
}
#endif				/* TESTING_H */
