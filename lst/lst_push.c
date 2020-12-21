/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:49:25 by archid-           #+#    #+#             */
/*   Updated: 2020/12/21 09:48:24 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		lst_push_front(t_lst lst, t_lstnode node)
{
	if (!lst || !node)
		return (lst);
	node->next = lst->head->next;
	lst->head->next->prev = node;
	node->prev = lst->head;
	lst->head->next = node;
	lst->size++;
	return (lst);
}

t_lst		lst_push_front_blob(t_lst lst, const void *blob,
								size_t size, bool alloc)
{
	if (!lst)
		return (NULL);
	else
		return (lst_push_front(lst, lst_node(blob, size, alloc)));
}

t_lst		lst_push_back(t_lst lst, t_lstnode node)
{
	if (!lst || !node)
		return (NULL);
	lst->tail->prev->next = node;
	node->prev = lst->tail->prev;
	node->next = lst->tail;
	lst->tail->prev = node;
	lst->size++;
	return (lst);
}

t_lst		lst_push_back_blob(t_lst lst, const void *blob,
								size_t size, bool alloc)
{
	if (!lst)
		return (NULL);
	else
		return (lst_push_back(lst, lst_node(blob, size, alloc)));
}
