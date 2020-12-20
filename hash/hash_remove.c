/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:39:38 by archid-           #+#    #+#             */
/*   Updated: 2020/12/20 00:23:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

bool			key_cmp(const t_hashnode *node, const char *key1)
{
	return !ft_strcmp(key1, node->key);
}

bool			hash_remove(t_hash h, const char *key)
{
	t_lstnode	walk;
	size_t		i;

	if (!h)
		return false;
	i = 0;
	while (i < h->size)
	{
		walk = lst_front(h->array[i]);
		while (walk)
		{
			if (key_cmp(walk->blob, key))
			{
				lst_remove(h->array[i], &walk);
				return (true);
			}
			lst_node_forward(&walk);
		}
		i++;
	}
	return (false);
}
