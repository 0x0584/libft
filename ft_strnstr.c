/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:50:51 by archid-           #+#    #+#             */
/*   Updated: 2019/03/31 19:04:15 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s, char *tofind, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (s[i] && --len)
	{
		j = 0;
		while (tofind[j] && s[i + j] == tofind[j])
			j++;
		if (tofind[j] == '\0')
			return (s + i);
		i++;
	}
	return (NULL);
}
