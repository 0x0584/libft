/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:54:26 by archid-           #+#    #+#             */
/*   Updated: 2019/03/30 23:55:32 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_uchar *dbuff;
	t_uchar *sbuff;

	i = 0;
	sbuff = (t_uchar *)malloc(n);
	dbuff = (t_uchar *)dest;
	while (i < n)
	{
		dbuff[i] = sbuff[i];
		i++;
	}
	return (dbuff);
}
