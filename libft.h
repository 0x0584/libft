/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:32:57 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 03:34:30 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ALLOC(type, size) ((char *)ft_memalloc(size + 1))

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef enum	e_bool
{
	false = (1 == 0),
	true = !(false)
}				t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **mem);
void			ft_bzero(void *s, size_t n);

char			*ft_strnew(size_t size);
void			ft_strdel(char **s);
void			ft_strclr(char *s);

char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strncat(char *dst, const char *src, size_t len);
char			*ft_strstr(char *s, char *to_find);
char			*ft_strnstr(char *s, char *tofind, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_iswhitespace(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlcat(char *s1, const char *s2, size_t len);

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_power(int x, int y);
int				ft_atoi(const char *s);

#endif
