/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 02:58:13 by archid-           #+#    #+#             */
/*   Updated: 2021/03/15 14:58:15 by archid-          ###   ########.fr       */
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
