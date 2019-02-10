/*
 * File: libft.h
 * Author: Anas Rchid
 * Description:
 *
 * Created: <2019-02-06 Wed 21:18:44>
 * Updated: <2019-02-10 Sun 20:22:01>
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

#ifndef LIBFT_H
#  define LIBFT_H
#  include <stdlib.h>

/* types */
typedef unsigned char t_uchar;
typedef enum e_bool {
	false = (1 == 0),
	true = !false
} t_bool;

/* memory related functions */
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void ft_bzero(void *s, size_t n);

/* string related functions */
size_t ft_strlen(const char *str);
char *ft_strdup(char *str);
char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, size_t n);
char *ft_strcat(char *dest, const char *src);
char *ft_strncat(char *dest, const char *src, size_t n);
char *ft_strlcat(char *dest, const char *src, size_t n);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *str, int c);
char *ft_strstr(const char *str, const char *to_find);
char *ft_strnstr(const char *str, const char *to_find, size_t n);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);

int ft_isdigit(int c);

#endif				/* LIBFT_H */
