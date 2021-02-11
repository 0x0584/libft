/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpeek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:26:20 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:39:20 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpeek(t_list **alst)
{
	t_list *foo;

	if ((alst && *alst))
	{
		foo = *alst;
		if ((*alst)->next)
			*alst = (*alst)->next;
		else
			*alst = NULL;
		foo->next = NULL;
		return (foo);
	}
	return (NULL);
}
