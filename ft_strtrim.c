/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:16:56 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 06:17:22 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	slen;
	char	*head;
	char	*tail;

	slen = ft_strlen(s);
	head = (char *)s;
	tail = (char *)s + ft_strlen(s) - 1;
	while (ISWHITESPC(*head))
		head++;
	while (ISWHITESPC(*tail))
		tail--;
	return (ft_strrdup(head, tail));
}
