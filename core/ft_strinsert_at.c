/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:58:08 by archid-           #+#    #+#             */
/*   Updated: 2020/12/21 09:44:55 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert_at(char **str, char const *src, size_t index)
{
	char	*foo;
	size_t	sizes[2];

	if (!str || !*str)
		return (NULL);
	sizes[0] = ft_strlen(*str);
	sizes[1] = ft_strlen(src);
	if (index > sizes[0] || !(foo = ft_strnew(sizes[0] + sizes[1])))
		return (NULL);
	ft_strncpy(foo, *str, index);
	ft_strncpy(foo + index, src, sizes[1]);
	ft_strncpy(foo + sizes[1] + index, *str + index, sizes[0] - index);
	ft_strdel(str);
	return (*str = foo);
}
