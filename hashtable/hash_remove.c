/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:39:38 by archid-           #+#    #+#             */
/*   Updated: 2023/01/14 16:35:17 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

bool			hash_remove(t_hashtable h, void *key)
{
	t_lstnode	walk;
	size_t		hash;
	t_hashtable_node	*tmp;

	if (!h)
		return (false);
	hash = h->hasher(key, h->size);
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!h->cmp(tmp->key, key))
		{
			lst_remove(h->array[hash], &walk);
			return (true);
		}
		lst_node_forward(&walk);
	}
	return (false);
}
