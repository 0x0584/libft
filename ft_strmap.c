/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:20:13 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:40:48 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buff;
	size_t	i;

	i = -1;
	if (!s || !(buff = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	while (s[++i])
		buff[i] = (*f)(s[i]);
	return (buff);
}
