/*
 * File: tst_striter.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 13:09:58>
 * Updated: <2019-02-21 Thu 13:21:20>
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

void inc(char *s) {
	char c = *s;
	char tosub = isupper(c) ? 'A' : 'a';

	if (isalpha(*s))
		c = (c - tosub + 0x0584) % 26 + tosub;
	*s = c;
}

int main(int argc, char *argv[]) {
	char *s;
	if (argc != 2)
		return 0;
	s = strdup(argv[1]);
	ft_striter(s, inc);
	printf("'%s' '%s'", argv[1], s);
	free(s);
	return 0;
}
