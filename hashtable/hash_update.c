/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:31:11 by archid-           #+#    #+#             */
/*   Updated: 2023/01/13 01:14:02 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void		insert(t_hashtable h, size_t hash, void *key, void *blob)
{
	t_hashtable_node	hnode;

	hnode = (t_hashtable_node){key, (void *)blob};
	h->array[hash] = lst_alloc(h->del);
	lst_push_back_blob(h->array[hash], &hnode, sizeof(t_hashtable_node), true);
}

void			hashtable_update(t_hashtable h, void *key, void *blob)
{
	size_t		hash;
	t_lstnode	walk;
	t_hashtable_node	hnode;
	t_hashtable_node	*tmp;

	if (!h || !blob || !key)
		return ;
	if (!h->array[hash = sfold(key, h->size, h->literal)])
		insert(h, hash, key, blob);
	else
	{
		walk = lst_front(h->array[hash]);
		while (walk)
			if (!h->cmp((tmp = walk->blob)->key, key))
			{
				h->del(tmp->blob);
				tmp->blob = (void *)blob;
				return ;
			}
			else
				lst_node_forward(&walk);
		hnode = (t_hashtable_node){key, (void *)blob};
		lst_push_front_blob(h->array[hash], &hnode, sizeof(t_hashtable_node), true);
	}
}
