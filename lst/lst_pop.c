/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:49:49 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:50:01 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lstnode	lst_pop_back(t_lst lst)
{
	t_lstnode node;

	if (lst_empty(lst))
		return (NULL);
	node = lst->tail->prev;
	lst->tail->prev = node->prev;
	node->prev->next = lst->tail;
	lst->size--;
	return (node);
}

void		*lst_pop_back_blob(t_lst lst)
{
	t_lstnode	tmp;
	void		*blob;

	if (lst_empty(lst))
		return (NULL);
	tmp = lst_pop_back(lst);
	blob = tmp->blob;
	lst_node_del_with(&tmp, blob_keep);
	return (blob);
}

t_lstnode	lst_pop_front(t_lst lst)
{
	t_lstnode node;

	if (lst_empty(lst))
		return (NULL);
	node = lst->head->next;
	node->next->prev = lst->head;
	lst->head->next = node->next;
	lst->size--;
	return (node);
}

void		*lst_pop_front_blob(t_lst lst)
{
	t_lstnode	tmp;
	void		*blob;

	if (lst_empty(lst))
		return (NULL);
	tmp = lst_pop_front(lst);
	blob = tmp->blob;
	lst_node_del_with(&tmp, blob_keep);
	return (blob);
}
