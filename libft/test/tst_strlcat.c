/*
 * File: tst_strlcat.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 13:25:22>
 * Updated: <2019-02-21 Thu 13:28:14>
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
	char *str;

	if (argc <= 3)
		return 0;
	sz += strlen(argv[1]);
	printf("'%s", argv[1]);
	while (i < argc - 1) {
		sz += strlen(argv[i]);
		printf(" %s", argv[i]);
		i++;
	}
	printf("' ");
	str = ft_memalloc(sz * sizeof(char));
	i = 1;
	while (i < argc - 1) {
		str = ft_strlcat(str, argv[i], atoi(argv[argc - 1]));
		i++;
	}
	printf("'%s'\n", str);
	free(str);
	return 0;
}
