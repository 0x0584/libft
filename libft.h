/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:32:57 by archid-           #+#    #+#             */
/*   Updated: 2021/01/22 15:57:40 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "types.h"

# define BUFF_SIZE						    16384
# define CACHE_SIZE							32

# define BASE_LHEX							"0123456789abcdef"
# define BASE_UHEX							"0123456789ABCDEF"
# define BASE_DEC							"0123456789"
# define BASE_OCT							"01234567"
# define BASE_BIN							"01"

struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

struct			s_int_array
{
	int		*base;
	size_t	size;
};

struct			s_list_container
{
	struct t_list *head;
	struct t_list *tail;
};

enum			e_string_position
{
	TOWARD_HEAD = true,
	TOWARD_TAIL = false
};

typedef struct	s_cache {
	int		fd;
	char	*base;
	size_t	size;
	size_t	length;
	size_t	index;
}				t_cache;

extern char		*g_buff;
extern bool		g_cache_ready;
extern t_cache	g_cache[CACHE_SIZE];

int				gnl(const int fd, char **line);
t_cache			*cache_alloc(const int fd);
void			cache_setup(void);
void			cache_grow(t_cache *cache);
bool			has_line(t_cache *cache, char **line);
void			gnl_cleanup(void);
int				gnl_clean(const int fd);

int				ft_vadprintf(const int fd, const char *fmt, va_list args_base);
int				ft_printf(const char *fmt, ...);
int				ft_dprintf(const int fd, const char *fmt, ...);
int				ft_asprintf(char **ret, const char *fmt, ...);
int				ft_snprintf(char *astr, size_t n, const char *fmt, ...);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_dumb_realloc(void **ptr, size_t old, size_t new);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **mem);
void			ft_free(void (*del)(void *o), void *ptr, ...);
void			ft_bzero(void *s, size_t n);

char			*ft_strchange(char **astr, char *s);
char			*ft_strinsert_at(char **str, char const *src, size_t index);
char			*ft_strreplace(char **str, char const *base, char const *to);
char			*ft_strpad(char **astr, char c, size_t n, bool left);
char			*ft_strsubswap(char **astr, const char *s1, const char *s2);
char			*ft_strctrim(char **str, char c, bool left);
char			*ft_strtoupper(char **str);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *str);
char			*ft_strrev(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
size_t			ft_strichr(const char *s, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strncat(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *s, const char *to_find);
char			*ft_strnstr(const char *s, const char *tofind, size_t len);
void			ft_strdel(char **s);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_strtolower(char **str);
size_t			ft_strlcat(char *s1, const char *s2, size_t len);
char			**ft_strsplit(char const *s, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strprepend(char **dest, const char *prefix);
void			ft_strappend(char **astr, const char *s);
char			*ft_strnonprintable(const char *str);

int				ft_atoi(const char *s);
long			ft_atol(const char *s);

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			striter_tolower(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnumber_fd(int n, int fd);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnumber(int n);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstiter_recu(t_list *lst, void (*f)(t_list *elem));
int				ft_lstadd(t_list **alst, t_list *new);
int				ft_lstpush(t_list **alst, t_list *e);
size_t			ft_lstlen(t_list *lst);
void			ft_lst_mergesort(t_list **alst, int (*cmp)(t_list *, t_list *));
void			lstdel_helper(void *content, size_t size);
void			lstiter_helper_as_int(t_list *nb);
t_list			*ft_lstdup(t_list *lst);

t_list			*ft_lstpeek(t_list **alst);
t_list			*ft_lstpop(t_list **alst);

char			*ft_strrdup(const char *head, const char *tail);
void			*ft_memdup(const void *mem, size_t n);
t_s16			ft_wordcount(char const *s, char using);

int				ft_power(int x, int y);
int				ft_sqrt(int nb);

t_s8			ft_digitcount(int n);
t_s32			ft_digitcount_128bit(t_s128 n);

int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_swap(void *u, void *v, size_t size);

char			*ft_itoa_base(t_s128 nb, const char *base);
char			*ft_utoa_base(t_u128 nb, const char *base);

void			**ft_lst_content_asarray(t_list *head, size_t *size);
int				*ft_lst_int_asarray(t_list *head, size_t *size);

/*
** ***************** added after macro ***************
*/

t_s64			max(t_s64 a, t_s64 b);
t_s64			min(t_s64 a, t_s64 b);
t_u64			umax(size_t a, size_t b);
t_u64			umin(size_t a, size_t b);
t_u64			ft_abs(t_s64 x);

void			*ft_calloc(size_t n, size_t sz);
void			strsplit_free(char **ptr);

void			print_memory(const void *addr, size_t size);

bool			ft_strprefix(const char *s, const char *pre);
bool			ft_strsuffix(const char *s, const char *suff);

#endif
