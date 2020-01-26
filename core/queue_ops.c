/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:59:15 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:00:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void		queue_enq(t_queue *queue, t_qnode *node)
{
	if (!queue || !node)
		return ;
	queue->tail->prev->next = node;
	node->prev = queue->tail->prev;
	node->next = queue->tail;
	queue->tail->prev = node;
}

t_qnode		*queue_deq(t_queue *queue)
{
	t_qnode *node;

	if (!queue || queue->head->next == queue->tail)
		return (NULL);
	node = queue->head->next;
	node->next->prev = queue->head;
	queue->head->next = node->next;
	return (node);
}

void		queue_push_front(t_queue *queue, t_qnode *node)
{
	if (!queue || !node)
		return ;
	node->next = queue->head->next;
	queue->head->next->prev = node;
	node->prev = queue->head;
	queue->head->next = node;
}

t_qnode		*queue_pop(t_queue *queue)
{
	t_qnode *node;

	if (!queue || queue->head->next == queue->tail)
		return (NULL);
	node = queue->tail->prev;
	queue->tail->prev = node->prev;
	node->prev->next = queue->tail;
	return (node);
}

void		queue_penq(t_queue *queue, t_qnode *node,
						bool (*cmp)(t_qnode *, t_qnode *))
{
	t_qnode *walk;
	bool	inserted;

	if (!queue || !node)
		return ;
	inserted = false;
	walk = queue->head->next;
	while (cmp && walk != queue->tail)
	{
		if (cmp(node, walk))
		{
			node->prev = walk->prev;
			node->next = walk;
			walk->prev->next = node;
			walk->prev = node;
			inserted = true;
			break ;
		}
		walk = walk->next;
	}
	if (!inserted)
		queue_enq(queue, node);
}
