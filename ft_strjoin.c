/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:42:27 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 01:11:55 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *buff;

	if (!(buff = ALLOC(char *, ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(buff, (char *)s1);
	ft_strcat(buff, (char *)s2);
	return (buff);
}
