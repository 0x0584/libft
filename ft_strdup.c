/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:04:18 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:40:11 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	length;
	char	*buff;

	i = -1;
	length = ft_strlen(str) + 1;
	if (!(buff = ft_calloc(length, sizeof(char))))
		return (NULL);
	while (++i < length - 1)
		buff[i] = str[i];
	return (buff);
}
