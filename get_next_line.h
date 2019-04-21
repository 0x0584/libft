/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/04/21 08:11:19 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"

# define NL						0x0A

# define BUFF_SIZE				10
# define IS_EOF(n)				(n < BUFF_SIZE)

# define CACHE_SIZE				2 * BUFF_SIZE
# define INCR_CACHE_SIZE(c)		((c)->size + CACHE_SIZE + 1)
# define ISFULL_CACHE(c)		((c)->length + 1 == c->size)

# define S_SIZE(s)				(ft_strlen(s) + 1)


/*
** this enumeration would hold some useful values for the rest
** of the program like the the tmp buffer indexes, and also
** return states: success, failure and eof
*/


/*
** who said C does not have a bool type?
*/

enum			e_bool
{
	false = (1 == 0),
	true = !false
};

enum			e_fuzzbuzz
{
	ibuffer, ifoo,
	ibar, icount,

	failure = -1, eof, success
};

/*
** FIXME: do I have to use this? or an array would be perfect!
*/

typedef struct	s_cache
{
	char			*buff;
	char			*nl;
	size_t			length;
	size_t			size;
}				t_cache;

int				cache_alloc(t_cache **cache);
int				cache_free(t_cache **cache);
int				cached_read(const int fd, char **line, char **args);

int				get_next_line(const int fd, char **line);

#endif
