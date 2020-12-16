/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:27:42 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:39:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	t_list *foo;
	t_list *bar;

	if (!(alst && *alst))
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
