/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:27:42 by archid-           #+#    #+#             */
/*   Updated: 2019/11/22 23:48:31 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	t_list *foo;
	t_list *bar;

	if (!SAFE_PTRVAL(alst))
		return (NULL);
	foo = *alst;
	bar = NULL;
	while (foo->next)
	{
		bar = foo;
		foo = foo->next;
	}
	foo->next = NULL;
	if (bar == NULL)
		*alst = NULL;
	else
		bar->next = NULL;
	return (foo);
}
