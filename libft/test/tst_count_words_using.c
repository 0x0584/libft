/*
 * File: tst_count_words_using.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-11 Mon 18:13:17>
 * Updated: <2019-02-12 Tue 02:07:55>
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

/* TODO: handle arguments rather than words */

#include "libft.h"
#include "testing.h"

int main(int argc, char *argv[]) {
	int i;
	t_uint exp_count;
	t_uint count;

	if (argc != 3) {
		i = 1;
		while (i < argc) {
			exp_count = ft_atoi(argv[i + 2]);
			count = ft_count_words_using(argv[i], argv[i + 1][0]);
			printf("'%s' has `%d' vs `%d'\n", argv[i], exp_count, count);
			i += 3;
		}
	}
	return 0;
}
