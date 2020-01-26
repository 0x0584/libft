/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:01:01 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:01:52 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void		queue_node_del(t_qnode **a_node, void (*del)(void *, size_t))
{
	if (!a_node || !*a_node)
		return ;
	(*del)((*a_node)->blob, (*a_node)->size);
	free(*a_node);
	*a_node = NULL;
}

void		queue_del(t_queue **q, void (*del)(void *, size_t))
{
	t_qnode *walk;
	t_qnode *tmp;

	if (!q)
		return ;
	walk = (*q)->head->next;
	while (walk != (*q)->tail)
	{
		tmp = walk;
		walk = walk->next;
		queue_node_del(&tmp, del);
	}
	queue_node_del(&(*q)->head, del);
	queue_node_del(&(*q)->tail, del);
	free(*q);
	*q = NULL;
}

void		queue_dry_del_helper(void *blob, size_t size)
{
	(void)blob;
	(void)size;
	return ;
}

void		queue_del_helper(void *blob, size_t size)
{
	if (size)
		free(blob);
}

void		queue_node_del_next(t_queue *q, t_qnode *node,
									void (*del)(void *, size_t))
{
	t_qnode *tmp;

	if (!q || !node || node == q->head || node == q->tail ||
			node->next == q->tail)
		return ;
	tmp = node->next;
	node->next = node->next->next;
	node->next->prev = node;
	del(tmp->blob, tmp->size);
	free(tmp);
}
