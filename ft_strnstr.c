/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:50:51 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 06:53:03 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s, char *tofind, size_t len)
{
	size_t i;
	size_t j;

	if (len == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (tofind[j] && s[i + j] == tofind[j] && i + j < len - 1)
			j++;
		if (tofind[j] == '\0')
			return (s + i);
		i++;
	}
	return (NULL);
}
