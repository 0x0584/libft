/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:55:01 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 17:13:30 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int		flag(int fl)
{
	return (1U << fl);
}

bool	is_flag(int val, int fl)
{
	return ((val & flag(fl)) != 0);
}

bool	has_flag(t_frmt *frmt, int fl)
{
	return (frmt && is_flag(frmt->flags, fl));
}

bool	is_hash(t_frmt *frmt)
{
	return (has_flag(frmt, FL_HASH));
}

bool	is_hex(t_frmt *frmt, t_conv c)
{
	return ((c == CONV_UHEX && is_hash(frmt)) || c == CONV_PTR);
}
