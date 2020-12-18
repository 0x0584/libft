/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:08:56 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:25:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const t_u16 g_f128bit_man = 63;
const t_u32 g_f128bit_bais = 16383;
const t_u64 g_f128bit_fullbais = g_f128bit_bais + g_f128bit_man;
const t_u64 g_f128bit_impl = (1ULL << g_f128bit_man);

const t_u16 g_f64bit_man = 52;
const t_u32 g_f64bit_bais = 1023;
const t_u64 g_f64bit_fullbais = (g_f64bit_man + g_f64bit_bais);
const t_u64 g_f64bit_impl = (1ULL << g_f64bit_man);

const t_u16 g_f32bit_man = 23;
const t_u32 g_f32bit_bais = 127;
const t_u64 g_f32bit_fullbais = (g_f32bit_man + g_f32bit_bais);
const t_u64 g_f32bit_impl = (1ULL << g_f32bit_man);

bool			is_odd(t_s64 num)
{
	return (num & 1);
}

bool			is_even(t_s64 num)
{
	return (!is_odd(num));
}
