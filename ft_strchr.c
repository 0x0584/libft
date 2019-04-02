/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 04:50:23 by archid-           #+#    #+#             */
/*   Updated: 2019/03/31 15:04:20 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = -1;
	tmp = (char *)s;
	while (tmp[++i])
		if (tmp[i] == (char)c)
			return ((char *)tmp + i);
	return ((char *)tmp);
}
