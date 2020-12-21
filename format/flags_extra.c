/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:55:01 by archid-           #+#    #+#             */
/*   Updated: 2020/12/21 09:40:32 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int		ft_flag(int fl)
{
	return (1U << fl);
}

bool	ft_is_flag(int val, int fl)
{
	return ((val & ft_flag(fl)) != 0);
}

bool	ft_has_flag(t_frmt *frmt, int fl)
{
	return (frmt && ft_is_flag(frmt->flags, fl));
}

bool	ft_is_hash(t_frmt *frmt)
{
	return (ft_has_flag(frmt, FL_HASH));
}

bool	ft_is_hex(t_frmt *frmt, t_conv c)
{
	return ((c == CONV_UHEX && ft_is_hash(frmt)) || c == CONV_PTR);
}
