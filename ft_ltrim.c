/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:46:58 by archid-           #+#    #+#             */
/*   Updated: 2019/04/01 20:59:41 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FIXME: return a pointer or a new string!?
 */

char	*ft_ltrim(const char *s)
{
	size_t i;

	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	return ((char *)s + i);
}
