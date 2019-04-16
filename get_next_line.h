/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/04/16 03:37:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE				10
# define CACHE_SIZE				(2 * BUFF_SIZE + 1)
# define S_LEN(s)				(ft_strlen(s))
# define S_SIZE(s)				(ft_strlen(s) + 1)
# define NL						0x0A

/*
** this enumeration would hold some useful values for the rest
** of the program like the the tmp buffer indexes, and also
** return states: success, failure and eof
*/

enum			e_fuzzbuzz
{
	ibuffer, ifoo, ibar, icount,

	failure = -1, eof, success
};

/*
** who said C does not have a bool type?
*/

typedef enum	e_bool
{
	false = (1 == 0),
	true = !false
}				t_bool;

/*
** FIXME: do I have to use this? or an array would be perfect!
*/

typedef struct	s_fileinfo
{
	int		fd;
	char	*rest;
}				t_fileinfo;

int				get_next_line(const int fd, char **line);

#endif
