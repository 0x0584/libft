/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 01:45:30 by archid-           #+#    #+#             */
/*   Updated: 2020/12/21 09:41:34 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "types.h"

# define FLAG_NIL							0U

typedef t_u16	t_flag;

t_flag			flag(t_u8 shift);
t_flag			flag_set(t_flag *flag, t_u8 shift);
t_flag			flag_unset(t_flag *flag, t_u8 shift);

bool			isflag(t_flag flag, t_u8 shift);

#endif
