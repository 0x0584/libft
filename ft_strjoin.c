/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:42:27 by archid-           #+#    #+#             */
/*   Updated: 2019/04/06 08:48:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *buff;
	size_t size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(buff = ALLOC(char *, size * sizeof(char))))
		return (NULL);
	ft_strcpy(buff, (char *)s1);
	ft_strcat(buff, (char *)s2);
	return (buff);
}
