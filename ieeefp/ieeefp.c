/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieeefp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:59:08 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 17:33:58 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ieeefp.h"
#include "format.h"

void	ieee_extract_parts(t_ieeefp *fp, t_u128 *man, t_s32 *exp)
{
	if (fp->type == IEEE_FLOAT)
	{
		*man = (fp->as.f.ieee.m + (fp->as.f.ieee.e ? g_f32bit_impl : 0ULL));
		*exp = (fp->as.f.ieee.e - g_f32bit_fullbais + (fp->as.f.ieee.e ?
														0 : 1));
	}
	else if (fp->type == IEEE_DOUBLE)
	{
		*man = (fp->as.d.ieee.m + (fp->as.d.ieee.e ?
									g_f64bit_impl : 0ULL));
		*exp = (fp->as.d.ieee.e - g_f64bit_fullbais + (fp->as.d.ieee.e ?
														0 : 1));
	}
	else
	{
		*man = (fp->as.ld.ieee.m1 + (fp->as.ld.ieee.e ?
										g_f128bit_impl : 0ULL));
		*exp = (fp->as.ld.ieee.e - g_f128bit_fullbais + (fp->as.ld.ieee.e ?
															0 : 1));
	}
}

void	ieee_extract_hex_parts(t_ieeefp *fp, t_u128 *man, t_s32 *exp)
{
	if (fp->type == IEEE_FLOAT)
	{
		*man = (fp->as.f.ieee.m + (fp->as.f.ieee.e ? g_f32bit_impl : 0ULL));
		*exp = (fp->as.f.ieee.e - g_f32bit_bais);
	}
	else if (fp->type == IEEE_DOUBLE)
	{
		*man = (fp->as.d.ieee.m + (fp->as.d.ieee.e ? g_f64bit_impl : 0ULL));
		*exp = (fp->as.d.ieee.e - g_f64bit_bais);
	}
	else
	{
		*man = (fp->as.ld.ieee.m1 + (fp->as.ld.ieee.e ? g_f128bit_impl : 0ULL));
		*exp = (fp->as.ld.ieee.e - g_f128bit_bais);
	}
}

bool	ieee_get_sign(t_ieeefp *fp)
{
	bool sign;

	if (fp->type == IEEE_FLOAT)
		sign = fp->as.f.ieee.s;
	else if (fp->type == IEEE_DOUBLE)
		sign = fp->as.d.ieee.s;
	else
		sign = fp->as.ld.ieee.s;
	return (sign);
}

bool	ieee_is_zero(t_ieeefp *fp)
{
	if (fp->type == IEEE_FLOAT)
		return (fp->as.f.f == 0.0);
	else if (fp->type == IEEE_DOUBLE)
		return (fp->as.d.d == 0.0);
	else
		return (fp->as.ld.ld == 0.0);
}

void	ieee_set_fp(t_ieeefp *fp, t_frmt *frmt)
{
	bool islong;

	islong = (frmt->length == MOD_L_CAP);
	if (islong)
		fp->as.ld.ld = frmt->data.ld;
	else
		fp->as.d.d = frmt->data.d;
	fp->type = islong ? IEEE_LONG_DOUBLE : IEEE_DOUBLE;
}
