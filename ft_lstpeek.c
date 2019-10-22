/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpeek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:26:20 by archid-           #+#    #+#             */
/*   Updated: 2019/10/22 03:50:50 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpeek(t_list **alst)
{
	t_list *foo;

	if (SAFE_PTRVAL(alst))
	{
		foo = *alst;
		if (foo->next)
			*alst = foo->next;
		else
			*alst = NULL;
		foo->next = NULL;
		return (foo);
	}
	return (NULL);
}
