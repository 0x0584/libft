/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:55:15 by archid-           #+#    #+#             */
/*   Updated: 2023/01/14 15:11:08 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

bool	hashtable_add(t_hashtable h, void *key, void *blob)
{
	size_t				hash;
	t_lstnode			walk;
	t_hashtable_node	hnode;
	t_hashtable_node	*tmp;

	if (!h || !blob || !key)
		return (false);
	if (!h->array[hash = h->hasher(key, h->size)])
	{
		hnode = (t_hashtable_node){key, (void *)blob};
		h->array[hash] = lst_alloc(h->del);
		lst_push_back_blob(h->array[hash], &hnode, sizeof(t_hashtable_node), true);
		return (true);
	}
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!h->cmp(tmp->key, key))
			return (false);
		lst_node_forward(&walk);
	}
	hnode = (t_hashtable_node){key, (void *)blob};
	lst_push_front_blob(h->array[hash], &hnode, sizeof(t_hashtable_node), true);
	return (true);
}

void	*hashtable_get(t_hashtable h, void *key, void *default_val)
{
	size_t				hash;
	t_lstnode			walk;
	t_hashtable_node	*tmp;

	if (!h->array[hash = h->hasher(key, h->size)])
		return ((void *)default_val);
	walk = lst_front(h->array[hash]);
	while (walk)
	{
		tmp = walk->blob;
		if (!h->cmp(tmp->key, key))
			return (tmp->blob);
		lst_node_forward(&walk);
	}
	return ((void *)default_val);
}

size_t	hashtable_count(t_hashtable h)
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

void	hashtable_iter(t_hashtable h, void (*callback)(void *key, void *blob))
{
	size_t				i;
	t_hashtable_node	*tmp;
	t_lstnode			walk;

	if (!h)
		return ;
	i = 0;
	while (i < h->size)
	{
		if (!(walk = lst_front(h->array[i++])))
			continue ;
		while (walk)
		{
			tmp = walk->blob;
			callback(tmp->key, tmp->blob);
			lst_node_forward(&walk);
		}
	}
}

void	hashtable_iter_arg(t_hashtable h, void *arg,
						void (*callback)(void *key, void *blob, void *arg))
{
	size_t		i;
	t_hashtable_node	*tmp;
	t_lstnode	walk;

	if (!h)
		return ;
	i = 0;
	while (i < h->size)
	{
		if (!(walk = lst_front(h->array[i++])))
			continue ;
		while (walk)
		{
			tmp = walk->blob;
			callback(tmp->key, tmp->blob, arg);
			lst_node_forward(&walk);
		}
	}
}
