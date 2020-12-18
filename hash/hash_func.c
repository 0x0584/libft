/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:55:15 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 12:57:11 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

bool	hash_add(t_hash h, const char *key, void *blob)
{
	size_t		hash;
	t_lstnode	walk;
	t_hashnode	hnode;
	t_hashnode	*tmp;

	if (!h || !blob || !key)
		return (false);
	if (!h->array[hash = sfold(key, h->size)])
	{
		hnode = (t_hashnode){ft_strdup(key), blob};
		h->array[hash] = lst_alloc(h->del);
		lst_push_back_blob(h->array[hash], &hnode, sizeof(t_hashnode), true);
		return (true);
	}
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!ft_strcmp(tmp->key, key))
			return (false);
		lst_node_forward(&walk);
	}
	hnode = (t_hashnode){ft_strdup(key), blob};
	lst_push_front_blob(h->array[hash], &hnode, sizeof(t_hashnode), true);
	return (true);
}

void	*hash_get(t_hash h, const char *key, void *default_val)
{
	size_t		hash;
	t_lstnode	walk;
	t_hashnode	*tmp;

	if (!h->array[hash = sfold(key, h->size)])
		return (default_val);
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!ft_strcmp(tmp->key, key))
			return (tmp->blob);
		lst_node_forward(&walk);
	}
	return (default_val);
}

size_t	hash_count(t_hash h)
{
	size_t size;
	size_t i;

	i = 0;
	size = 0;
	if (!h)
		return (size);
	while (i < h->size)
		size += lst_size(h->array[i++]);
	return (size);
}

void	hash_iter(t_hash h, void (*callback)(const char *key, void *blob))
{
	size_t		i;
	t_hashnode	*tmp;
	t_lstnode	walk;
	t_lst		lst;

	if (!h)
		return ;
	i = 0;
	while (i < h->size)
	{
		if (!(lst = h->array[i++]))
			continue ;
		walk = lst_front(lst);
		while (walk)
		{
			tmp = walk->blob;
			callback(tmp->key, tmp->blob);
			lst_node_forward(&walk);
		}
	}
}
