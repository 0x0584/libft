/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:43:50 by archid-           #+#    #+#             */
/*   Updated: 2019/03/31 00:00:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	t_uchar *buff;

	i = 0;
	buff = (t_uchar *)s;
	while (i < n)
		buff[i++] = (t_uchar)c;
	return (buff);
}
