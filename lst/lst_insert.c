/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:51:44 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:51:58 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		lst_insert_at(t_lst lst, t_lstnode at, t_lstnode node)
{
	if (!lst || !at || !node || at == node)
		return (lst);
	else if (at == lst->head)
		return (lst_push_front(lst, node));
	else if (at == lst->tail)
		return (lst_push_back(lst, node));
	node->prev = at->prev;
	at->prev->next = node;
	at->prev = node;
	node->next = at;
	lst->size++;
	return (lst);
}

t_lst		lst_insert_after(t_lst lst, t_lstnode before, t_lstnode node)
{
	if (!lst || !before || !node)
		return (lst);
	else if (before == lst->tail)
		return (lst_push_back(lst, node));
	else
		return (lst_insert_at(lst, before->next, node));
}

t_lst		lst_insert_before(t_lst lst, t_lstnode after, t_lstnode node)
{
	if (!lst || !after || !node)
		return (lst);
	else if (after == lst->head)
		return (lst_push_front(lst, node));
	else
		return (lst_insert_at(lst, after->prev, node));
}
