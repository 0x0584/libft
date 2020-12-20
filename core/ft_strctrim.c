/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:58:08 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 17:30:46 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char **str, char c, bool left)
{
	char *head;
	char *tail;
	char *tmp;

	if (!str || !*str || !c)
		return NULL;
	head = *str;
	tail = head + ft_strlen(*str) - 1;
	while (*head && tail > *str && (left ? *head : *tail) == c)
		(void)(left ? head++ : tail--);
	tmp = ft_strrdup(head, tail);
	ft_strdel(str);
	return (*str = tmp);
}
