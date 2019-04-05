/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:35:27 by archid-           #+#    #+#             */
/*   Updated: 2019/04/04 00:07:15 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *s, char *tofind)
{
	size_t i;
	size_t j;

	i = 0;
	while (s[i])
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
