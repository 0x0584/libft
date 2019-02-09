/*
 * File: ft_print_combn.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-09 Sat 01:59:29>
 * Updated: <2019-02-09 Sat 04:50:17>
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

/*
 * idea:
 * =====
 *
 * create a function that would serve as looper function
 * and then keep testing if we have reached the end or not.
 * if so, print the array at the current state.
 */

#include <unistd.h>

#define MAX_N		(10)

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putstr(char *str) {
	while (*str)
		ft_putchar(*str++);
}

void print_array(int *array, int size) {
	int i;

	i = 0;
	while (i < size)
		ft_putchar(array[i++] + '0');
	if (array[0] != size - 1)
		ft_putstr(", ");
}

void looper(int *array, int start, int end, int current) {
	int i;

	i = start;
	if (current == end)
		print_array(array, end);
	else
		while (i <= end && (end - i + 1) >= end - current)
			looper(array, ++i, end, current + 1);
}

void ft_print_combn(int n) {
	int arr[MAX_N] = {
		0, 1, 2, 3, 4,
		5, 6, 7, 8, 9
	};

	looper(arr, 0, n, 0);
}
