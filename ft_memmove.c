/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:54:26 by archid-           #+#    #+#             */
/*   Updated: 2019/04/03 03:22:04 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_uchar *dbuff;
	t_uchar *sbuff;

	i = -1;
	sbuff = (t_uchar *)malloc(n * sizeof(t_uchar));
	dbuff = (t_uchar *)dest;
	ft_memcpy(sbuff, src, n);
	while (++i < n)
		dbuff[i] = sbuff[i];
	free(sbuff);
	return (dbuff);
}
