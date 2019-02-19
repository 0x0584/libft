/*
 * File: tst_strcat.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-19 Tue 02:57:26>
 * Updated: <2019-02-19 Tue 03:22:57>
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
	size_t sz = 1;
	int i = 2;
	char *str, *test;

	if (argc <= 2)
		return 0;
	sz += strlen(argv[1]);
	printf("'%s", argv[1]);
	while (i < argc) {
		sz += strlen(argv[i]);
		printf(" %s", argv[i]);
		i++;
	}
	str = ft_memalloc(sz * sizeof(char));
	test = ft_memalloc(sz * sizeof(char));
	i = 1;
	while (i < argc) {
		str = ft_strcat(str, argv[i]);
		test = strcat(test, argv[i]);
		i++;
	}
	printf("' ('%s' vs '%s')\n", str, test);
	free(test);
	free(str);
	return 0;
}
