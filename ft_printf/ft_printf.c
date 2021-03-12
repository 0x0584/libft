/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 02:58:13 by archid-           #+#    #+#             */
/*   Updated: 2019/11/22 18:56:28 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	int		n_chars;
	va_start(args, fmt);
	n_chars = ft_vadprintf(1, fmt, args);
	va_end(args);
	return (n_chars);
}
