/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 02:27:35 by archid-           #+#    #+#             */
/*   Updated: 2019/10/24 02:29:24 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strtolower(char **astr)
{
	char *s;

	if (!SAFE_PTRVAL(astr))
		return ;
	s = *astr;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
}
