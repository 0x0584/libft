/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:39:38 by archid-           #+#    #+#             */
/*   Updated: 2023/01/13 00:48:28 by archid-          ###   ########.fr       */
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
	hash = sfold(key, h->size, h->literal);
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
