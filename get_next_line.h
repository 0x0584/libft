/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/04/15 03:57:53 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE				10

# include <unistd.h>
# include "libft/libft.h"

enum			e_fuzzbuzz
{
	buffer, foo, bar, count,

	failure = -1, eof, success
};

typedef struct	s_fileinfo
{
	int		fd;
	char	*rest;
}				t_fileinfo;

int				get_next_line(const int fd, char **line);

#endif
