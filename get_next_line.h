/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/04/13 20:26:16 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE				 32

# define RET_FAILURE			-1
# define RET_EOF				 0
# define RET_SUCCESS			 1

# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_fileinfo
{
	int		fd;
	char	*rest;
}				t_fileinfo;

int		get_next_line(const int fd, char **line);

#endif
