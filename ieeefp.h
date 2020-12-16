/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieeefp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:00:10 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 16:56:57 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IEEEFP_H
# define IEEEFP_H

# include "types.h"

# ifndef MACHINE_IS_LITTLE_ENDIAN
#  error this implementation works on Little Endian machines only.
# endif

extern const t_u16 g_f128bit_man;
extern const t_u32 g_f128bit_bais;
extern const t_u64 g_f128bit_fullbais;
extern const t_u64 g_f128bit_impl;

extern const t_u16 g_f64bit_man;
extern const t_u32 g_f64bit_bais;
extern const t_u64 g_f64bit_fullbais;
extern const t_u64 g_f64bit_impl;

extern const t_u16 g_f32bit_man;
extern const t_u32 g_f32bit_bais;
extern const t_u64 g_f32bit_fullbais;
extern const t_u64 g_f32bit_impl;

union				u_ieee754_float
{
	float	f;
	t_u32	i;
	struct			s_ieee_float
	{
		t_u32	m:23;
		t_u8	e:8;
		t_u8	s:1;
	}		ieee;
};

union				u_ieee754_double
{
	double	d;
	t_u64	i;
	struct			s_ieee_double
	{
		t_u64	m:52;
		t_u16	e:11;
		t_u8	s:1;
	}		ieee;
};

union				u_ieee754_long_double
{
	long double		ld;
	t_u128			i;

	struct			s_ieee_long_double
	{
		t_u64	m1:63;
		t_u64	m2:1;
		t_u16	e:15;
		t_u8	s:1;
	}				ieee;
};

typedef enum		e_ieee_floating_point_types
{
	IEEE_FLOAT,
	IEEE_DOUBLE,
	IEEE_LONG_DOUBLE,
}					t_ieeetype;

typedef enum		e_special_values
{
	IEEE_NA,
	IEEE_INFINI_P,
	IEEE_INFINI_N,
	IEEE_NOT_A_NUMBER,
}					t_ieeesp;

typedef struct		s_ieee_floating_point
{
	t_ieeetype				type;
	union			u_ieeefp
	{
		union u_ieee754_long_double ld;
		union u_ieee754_double		d;
		union u_ieee754_float		f;
	}						as;
}					t_ieeefp;

typedef enum		e_ieee_floating_point_format
{
	IEEE_HEX,
	IEEE_EXPONENT,
	IEEE_NORMAL,
	IEEE_SUITABLE
}					t_ieee_fmt;

void				ieee_sci_style(char **astr, t_s32 exp, bool upcase);
char				*ieee_hex_style(t_ieeefp *fp, t_u32 prec, bool upcase);
void				ieee_suitable_style(char **astr, bool upcase);
void				ieee_extract_parts(t_ieeefp *fp, t_u128 *man, t_s32 *exp);
void				ieee_extract_hex_parts(t_ieeefp *fp, t_u128 *man,
												t_s32 *exp);
bool				ieee_get_sign(t_ieeefp *fp);
bool				ieee_is_zero(t_ieeefp *fp);

/*
** ************* added after marco removal *************
*/

bool				is_even(t_s64 num);
bool				is_odd(t_s64 num);

#endif
