/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:34:02 by archid-           #+#    #+#             */
/*   Updated: 2019/04/04 19:56:24 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	i;

	i = -1;
	buff = (char *)malloc(ft_strlen(s) * sizeof(char));
	while (s[++i])
		buff[i] = (*f)(i, s[i]);
	return (buff);
}
