/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 03:26:08 by archid-           #+#    #+#             */
/*   Updated: 2019/09/28 17:54:52 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	if (s)
	    return (write(fd, s, ft_strlen(s)));
	else
	    return (write(fd, "(null)", ft_strlen("(null)")));
}
