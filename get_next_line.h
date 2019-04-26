/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/04/24 23:12:04 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"

# define NL						0x0A
# define NIL					0x00

# define BUFF_SIZE				10
# define IS_EOF(n)				(n < BUFF_SIZE)

# define CACHE_SIZE				2 * BUFF_SIZE
# define INCR_CACHE_SIZE(c)		((c)->size + CACHE_SIZE + 1)
# define ISFULL_CACHE(c)		((c)->length + 1 == c->size)

# define S_SIZE(s)				(ft_strlen(s) + 1)

# define ASSERT_RET(expr, ret)	if ((expr)) return (ret)
# define UNLESS_RET(expr, ret)	if (!(expr)) return (ret)

enum			e_gnl_bool
{
	false = (1==0),
	true = !false
};

enum			e_gnl_exit
{
	failure = -1, eof, success
};

/*
** FIXME: find how to bring this idea to life!!!
*/

typedef struct	s_cache
{
	char			*buff;
	char			*nl;
	size_t			length;
	size_t			size;
}				t_cache;

int				read_file(const int fd, char **cache, char **line);
int				extract_nl_line(char **cache, char **line);
int				get_next_line(const int fd, char **line);

#endif
