/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 01:22:11 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 17:07:51 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <wchar.h>

# define INT_VALMAX 2147483647
# define INT_VALMIN -2147483648

/*
** there's a good question on how to get the type of endian on your machine
** https://stackoverflow.com/q/12791864/5744492
*/

# define MACHINE_IS_LITTLE_ENDIAN

/*
**			   --------------- Number types ---------------
*/

typedef char				t_s8;
typedef short				t_s16;
typedef int					t_s32;
typedef long				t_s64;
typedef long long			t_s128;

typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef unsigned int		t_u32;
typedef unsigned long		t_u64;
typedef unsigned long long	t_u128;

typedef void				*t_obj;

typedef struct s_int_array	t_intarr;

typedef struct s_list		t_list;

#endif
