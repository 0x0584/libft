/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:53:21 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:37:25 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst && *alst && new)
	{
		tmp = *alst;
		new->next = tmp;
		*alst = new;
	}
	if (!alst)
		return (0);
	else if (!*alst)
	{
		*alst = new;
		new->next = NULL;
	}
	return (1);
}
