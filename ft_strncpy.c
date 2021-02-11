/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:34:01 by archid-           #+#    #+#             */
/*   Updated: 2020/11/26 21:49:47 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (dst && src && src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (dst && i < len)
		dst[i++] = '\0';
	return (dst);
}
