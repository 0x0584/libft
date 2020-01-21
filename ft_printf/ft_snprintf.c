/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:52:11 by archid-           #+#    #+#             */
/*   Updated: 2020/01/22 14:50:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int		ft_snprintf(char *astr, size_t n, const char *fmt, ...)
{
	va_list args;
	t_buff	*buff;
	t_list	*lstfrmt;
	int		n_chars;

	lstfrmt = NULL;
	n_chars = 0;
	if (!astr || !(buff = buff_alloc(0x20)))
		return (-1);
	va_start(args, fmt);
	format_parse(fmt, &lstfrmt);
	format_populate(&lstfrmt, &args);
	n_chars = format_to_buff(lstfrmt, buff);
	ft_lstdel(&lstfrmt, format_free);
	va_end(args);
	if (n_chars >= 0)
		ft_strncpy(astr, buff->base, n);
	buff_free(&buff);
	return (n);
}
