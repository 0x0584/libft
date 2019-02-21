/*
 * File: tst_strmapi.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-21 Thu 13:50:39>
 * Updated: <2019-02-21 Thu 13:59:10>
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

/* is this enigma? */
char transform(unsigned int i, char c) {
	char tosub = isupper(c) ? 'A' : 'a';
	if (isalpha(c))
		c = (c - tosub + 0x0584 - i) % 26 + tosub;
	return c;
}

int main(int argc, char *argv[]) {
	char *s;
	if (argc != 2)
		return 0;
	s = ft_strmapi(argv[1], transform);
	printf("'%s' '%s'", argv[1], s);
	free(s);
	return 0;
}
