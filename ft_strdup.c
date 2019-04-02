/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:04:18 by archid-           #+#    #+#             */
/*   Updated: 2019/03/31 15:12:01 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*buff;

	i = -1;
	len = ft_strlen(str);
	buff = (char *)malloc((len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (++i < len)
		buff[i] = str[i];
	buff[i] = '\0';
	return (buff);
}
