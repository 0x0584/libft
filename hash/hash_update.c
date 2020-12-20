/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:31:11 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 12:34:45 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	hash_update(t_hash h, const char *key, const void *blob)
{
	size_t		hash;
	t_lstnode	walk;
	t_hashnode	hnode;
	t_hashnode	*tmp;

	if (!h || !blob || !key)
		return ;
	if (!h->array[hash = sfold(key, h->size)])
	{
		hnode = (t_hashnode){ft_strdup(key), (void *)blob};
		h->array[hash] = lst_alloc(h->del);
		lst_push_back_blob(h->array[hash], &hnode, sizeof(t_hashnode), true);
		return ;
	}
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!ft_strcmp(tmp->key, key))
		{
			h->del(tmp->blob);
			tmp->blob = (void *)blob;
			return ;
		}
		lst_node_forward(&walk);
	}
	hnode = (t_hashnode){ft_strdup(key), (void *)blob};
	lst_push_front_blob(h->array[hash], &hnode, sizeof(t_hashnode), true);
}
