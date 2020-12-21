/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:52:59 by archid-           #+#    #+#             */
/*   Updated: 2020/12/21 09:48:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		lst_insertion_sort(t_lst lst,
								int (*cmp)(const void *, const void *))
{
	t_lstnode walk;
	t_lstnode front;
	t_lstnode pivot;

	if (lst_size(lst) < 2)
		return (lst);
	walk = lst_front(lst);
	while (walk)
	{
		front = lst_front(lst);
		pivot = walk;
		lst_node_forward(&walk);
		while (front != pivot)
		{
			if (cmp(front->blob, pivot->blob) > 0)
				lst_node_forward(&front);
			else
			{
				lst_insert_at(lst, front, lst_extract(lst, pivot));
				break ;
			}
		}
	}
	return (lst);
}
