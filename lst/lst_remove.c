/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:52:09 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:52:20 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		lst_remove(t_lst lst, t_lstnode *node)
{
	t_lstnode tmp;

	if ((tmp = lst_extract(lst, *node)))
	{
		lst_node_del(lst, &tmp);
		*node = NULL;
	}
}

void		lst_remove_next(t_lst lst, t_lstnode node)
{
	t_lstnode tmp;

	if (node)
	{
		tmp = node->next;
		lst_remove(lst, &tmp);
	}
}

void		lst_remove_previous(t_lst lst, t_lstnode node)
{
	t_lstnode tmp;

	if (node)
	{
		tmp = node->prev;
		lst_remove(lst, &tmp);
	}
}
