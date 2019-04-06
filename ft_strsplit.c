/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 06:51:01 by archid-           #+#    #+#             */
/*   Updated: 2019/04/06 09:51:47 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**aspltd;
	char	*range[2];
	size_t	count;
	size_t	index;

	index = 0;
	count = ft_wordcount(s, c) + 1;
	if (!(aspltd = ALLOC(char **, count * sizeof(char *))))
		return (NULL);
	while (index < count - 1)
	{
		while (*s && *s == c)
			s++;
		range[0] = (char *)s;
		while (*s && *s != c)
			s++;
		range[1] = (char *)s - 1;
		aspltd[index++] = ft_strrdup(range[0], range[1]);
	}
	return (aspltd);
}
