/*
 * File: ft_strsplit.c
 * Author: Anas Rchid (0x0584)
 *
 * Created: <2019-02-11 Mon 02:42:24>
 * Updated: <2019-02-12 Tue 00:03:48>
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

char **_get_ranges(char const *s, char c) {
	char **ranges;
	t_uint sz;
	t_uint i;

	i = 0;
	sz = ft_count_words_using(s, c) * 2;
	ranges = (char **) ft_memalloc((sz + 1) * sizeof(char *));
	if (ranges == NULL)
		return (NULL);
	ranges[sz] = NULL;
	while (*s && sz) {
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break;
		ranges[i++] = (char *) s;
		while (*s && *s != c)
			s++;
		ranges[i++] = (char *) s - 1;
	}
	return (ranges);
}

char **ft_strsplit(char const *s, char c) {
	char **ranges;
	char **words;
	t_uint sz;
	t_uint i;

	i = 0;
	ranges = _get_ranges(s, c);
	sz = ft_count_words_using(s, c);
	words = (char **) ft_memalloc((sz + 1) * sizeof(char *));
	words[sz] = NULL;
	while (ranges[i]) {
		words[i / 2] = ft_strrdup(ranges[i], ranges[i + 1]);
		i += 2;
	}
	free(ranges);
	return (words);
}
