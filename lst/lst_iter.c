/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:50:49 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:51:26 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		lst_iter_arg(t_lst lst, bool front, void *arg,
							void (*apply_arg)(void *blob, void *arg))
{
	t_lstnode walk;

	if (lst_empty(lst))
		return ;
	walk = front ? lst->head->next : lst->tail->prev;
	while (walk != (front ? lst->tail : lst->head))
	{
		apply_arg(walk->blob, arg);
		walk = front ? walk->next : walk->prev;
	}
}

void		lst_iter(t_lst lst, bool front, void (*apply)(void *blob))
{
	t_lstnode walk;

	if (lst_empty(lst))
		return ;
	walk = front ? lst->head->next : lst->tail->prev;
	while (walk != (front ? lst->tail : lst->head))
	{
		apply(walk->blob);
		walk = front ? walk->next : walk->prev;
	}
}

void		lst_iteri_arg(t_lst lst, bool front, void *params,
							void (*index_apply_arg)(void *blob, size_t index,
													void *arg))
{
	t_lstnode	walk;
	size_t		i;

	if (lst_empty(lst))
		return ;
	i = 0;
	walk = front ? lst->head->next : lst->tail->prev;
	while (walk != (front ? lst->tail : lst->head))
	{
		index_apply_arg(walk->blob, i++, params);
		walk = front ? walk->next : walk->prev;
	}
}

void		lst_iteri(t_lst lst, bool front,
						void (*index_apply)(void *blob, size_t index))
{
	t_lstnode	walk;
	size_t		i;

	if (lst_empty(lst))
		return ;
	i = 0;
	walk = front ? lst->head->next : lst->tail->prev;
	while (walk != (front ? lst->tail : lst->head))
	{
		index_apply(walk->blob, i++);
		walk = front ? walk->next : walk->prev;
	}
}
