/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:53:29 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:57:56 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		lst_copy(t_lst lst, void *(*func_copy)(void *), void (*del)(void *))
{
	t_lst		copy;
	t_lstnode	walk;

	if (!(walk = lst_front(lst)) || !func_copy)
		return (NULL);
	copy = lst_alloc(del);
	while (walk)
	{
		lst_push_back_blob(copy, func_copy(walk->blob), walk->size, false);
		lst_node_forward(&walk);
	}
	return (copy);
}

t_lst		lst_copy_shallow(t_lst lst)
{
	return (lst_copy(lst, blob_identity, blob_keep));
}

t_lst		lst_copy_deep(t_lst lst, void *(copy)(void *))
{
	return (lst_copy(lst, copy, blob_free));
}
