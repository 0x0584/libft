/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:54:26 by archid-           #+#    #+#             */
/*   Updated: 2019/04/07 06:54:13 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_byte	*dbuff;
	t_byte	*sbuff;

	i = -1;
	dbuff = (t_byte *)dest;
	sbuff = (t_byte *)malloc(n * sizeof(t_byte));
	ft_memcpy(sbuff, src, n);
	ft_memcpy(dest, sbuff, n);
	free(sbuff);
	return (dbuff);
}
