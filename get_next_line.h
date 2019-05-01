/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/05/01 20:28:00 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define NL						0x0A
# define NIL					0x00

# define BUFF_SIZE				0x20
# define FD_SIZE				0xFF

# define ASSERT_RET(expr, ret)	if ((expr)) return (ret)
# define UNLESS_RET(expr, ret)	if (!(expr)) return (ret)

enum			e_gnl_bool
{
	false = (1 == 0),
	true = !false
};

enum			e_gnl_exit
{
	failure = -1, eof, success
};

ssize_t			cached_read(const int fd, char **cache);
int				extract_nl_line(char **cache, char **line);
int				get_next_line(const int fd, char **line);

#endif
