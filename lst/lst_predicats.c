/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_predicats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:47:40 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 00:28:38 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

bool		lst_any(t_lst lst, const void *val,
						bool (*func)(const void *, const void *))
{
	t_lstnode walk;

	walk = lst_front(lst);
	while (walk)
	{
		if (func(walk->blob, val))
			return (true);
		lst_node_forward(&walk);
	}
	return (false);
}

bool		lst_all(t_lst lst, const void *val,
						bool (*func)(const void *, const void *))
{
	t_lstnode walk;

	if (lst_empty(lst))
		return (false);
	walk = lst_front(lst);
	while (walk)
	{
		if (!func(walk->blob, val))
			return (false);
		lst_node_forward(&walk);
	}
	return (true);
}

bool		lst_none(t_lst lst, const void *val,
						bool (*func)(const void *, const void *))
{
	t_lstnode walk;

	walk = lst_front(lst);
	while (walk)
	{
		if (func(walk->blob, val))
			return (false);
		lst_node_forward(&walk);
	}
	return (true);
}
