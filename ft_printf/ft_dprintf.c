/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:15:06 by archid-           #+#    #+#             */
/*   Updated: 2019/11/22 18:56:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int		ft_dprintf(const int fd, const char *fmt, ...)
{
	va_list		args;
	int			n_chars;

	va_start(args, fmt);
	n_chars = ft_vadprintf(fd, fmt, args);
	va_end(args);
	return (n_chars);
}
