/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:53:32 by archid-           #+#    #+#             */
/*   Updated: 2019/03/30 23:05:08 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	t_uchar *dbuff;
	t_uchar *sbuff;

	i = 0;
	dbuff = (t_uchar *)dest;
	sbuff = (t_uchar *)src;
	while (i < n)
	{
		dbuff[i] = sbuff[i];
		if (sbuff[i] == (t_uchar)c)
			return (dbuff + i + 1);
		i++;
	}
	return (NULL);
}
