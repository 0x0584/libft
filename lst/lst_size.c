/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:56:22 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:56:37 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

size_t		lst_size(t_lst lst)
{
	return (lst ? lst->size : 0);
}

bool		lst_empty(t_lst lst)
{
	return (!lst || lst->head->next == lst->tail);
}

t_lst		lst_clear(t_lst lst)
{
	t_lstnode tmp;

	while (!lst_empty(lst))
	{
		tmp = lst_pop_back(lst);
		lst_node_del(lst, &tmp);
	}
	return (lst);
}

t_lst		lst_shrink(t_lst lst, bool from_head, size_t size)
{
	t_lstnode (*func)(t_lst);
	t_lstnode tmp;

	if (lst_size(lst) <= size)
		return (lst);
	func = from_head ? lst_pop_front : lst_pop_back;
	while (lst_size(lst) > size)
	{
		tmp = func(lst);
		lst_node_del(lst, &tmp);
	}
	return (lst);
}
