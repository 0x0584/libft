/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 01:44:26 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 02:01:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

t_flag			flag(t_u8 shift)
{
	return (shift < sizeof(t_flag) ? 1U << shift : 0);
}

t_flag			flag_set(t_flag *fl, t_u8 shift)
{
	return (*fl |= flag(shift));
}

t_flag			flag_unset(t_flag *fl, t_u8 shift)
{
	return (*fl |= ~flag(shift));
}

bool			isflag(t_flag fl, t_u8 shift)
{
	return (fl & flag(shift));
}
