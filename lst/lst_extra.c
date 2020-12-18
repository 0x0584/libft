/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:55:16 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:56:51 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		*lst_front_blob(t_lst lst)
{
	t_lstnode front;

	if (!(front = lst_front(lst)))
		return (NULL);
	return (front->blob);
}

void		*lst_rear_blob(t_lst lst)
{
	t_lstnode rear;

	if (!(rear = lst_rear(lst)))
		return (NULL);
	return (rear->blob);
}

bool		lst_node_forward(t_lstnode *anode)
{
	t_lstnode next;

	if (!anode || !*anode)
		return (false);
	next = (*anode)->next;
	return (*anode = next->next ? next : NULL);
}

bool		lst_node_backward(t_lstnode *anode)
{
	t_lstnode prev;

	if (!anode || !*anode)
		return (false);
	prev = (*anode)->prev;
	return (*anode = prev->prev ? prev : NULL);
}
