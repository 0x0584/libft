/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:45:03 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 03:30:56 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrdup(const char *head, const char *tail)
{
	char *buff;
	size_t length;

	length = 0;
	while (head + length < tail)
		length++;
	if (!(buff = ALLOC(char *, length + 1)))
		return (NULL);
	while (head + --length >= head)
		buff[length] = head[length];
	return (buff);
}
