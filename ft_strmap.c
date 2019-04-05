/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:20:13 by archid-           #+#    #+#             */
/*   Updated: 2019/04/04 20:22:46 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buff;
	size_t	i;

	i = -1;
	buff = (char *)malloc(ft_strlen(s) * sizeof(char));
	while (s[++i])
		buff[i] = (*f)(s[i]);
	return (buff);
}
