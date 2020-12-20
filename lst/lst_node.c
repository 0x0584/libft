/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:45:07 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 00:30:23 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lstnode	lst_node(const void *blob, size_t size, bool alloc)
{
	t_lstnode node;

	node = malloc(sizeof(struct s_lst_node));
	node->size = blob ? size : 0;
	if (alloc)
		node->blob = blob ? ft_memcpy(malloc(size), blob, size) : NULL;
	else
		node->blob = (void *)blob;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void		lst_node_del_with(t_lstnode *anode, void (*del)(void *blob))
{
	if (!anode || !*anode)
		return ;
	(*del)((*anode)->blob);
	free(*anode);
	*anode = NULL;
}

void		lst_node_del(t_lst lst, t_lstnode *anode)
{
	lst_node_del_with(anode, lst->del);
}

void		lst_node_free(t_lst lst, t_lstnode anode)
{
	lst_node_del(lst, &anode);
}
