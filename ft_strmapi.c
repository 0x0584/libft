/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:34:02 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:41:05 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	i;

	i = -1;
	if (!s || !(buff = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	while (s[++i])
		buff[i] = (*f)(i, s[i]);
	return (buff);
}
