/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:26:58 by archid-           #+#    #+#             */
/*   Updated: 2019/12/01 19:29:28 by archid-          ###   ########.fr       */
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

t_qnode 	*queue_deq(t_queue *queue)
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
	queue->head->prev = node;
	queue->head->next = node;
	node->prev = queue->head;
}

t_qnode 	*queue_peek(t_queue *queue)
{
	t_qnode *node;

	if (!queue || queue->head->next == queue->tail)
		return (NULL);
	node = queue->head->next;
	queue->head->next = node->next;
	node->next->prev = queue->head;
	return (node);
}

void		queue_iter(t_queue *q, void (*f)(t_qnode *))
{
	t_qnode *walk;

	if (!q || q->head->next == q->tail)
		return ;
	walk = q->head->next;
	while (walk != q->tail)
	{
		(*f)(walk);
		walk = walk->next;
	}
}
