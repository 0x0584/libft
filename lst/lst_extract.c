/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:52:30 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:52:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lstnode	lst_extract(t_lst lst, t_lstnode node)
{
	if (!lst || !node || lst->head == node || lst->tail == node)
		return (NULL);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	lst->size--;
	return (node);
}

void		*lst_extract_blob(t_lst lst, t_lstnode *node)
{
	t_lstnode	tmp;
	void		*blob;

	if (!node || !*node || !(tmp = lst_extract(lst, *node)))
		return (NULL);
	blob = tmp->blob;
	lst_node_del_with(&tmp, blob_keep);
	*node = NULL;
	return (blob);
}
