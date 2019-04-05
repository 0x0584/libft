/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:16:56 by archid-           #+#    #+#             */
/*   Updated: 2019/04/05 01:29:13 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	head;
	size_t	tail;
	size_t	slen;

	head = 0;
	tail = 0;
	slen = ft_strlen(s);
	while (ft_iswhitespace(s[head]))
		head++;
	while (ft_iswhitespace(s[slen - tail + 1]))
		tail++;
	return (ft_strsub(s, head, slen - tail));
}
