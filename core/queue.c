/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:11 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:03:32 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_qnode		*queue_node(void *blob, size_t size)
{
	t_qnode *node;

	node = (t_qnode *)malloc(sizeof(t_qnode));
	node->size = blob ? size : 0;
	node->blob = blob ? ft_memcpy(malloc(size), blob, size) : NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_queue		*queue_init(void)
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->head = queue_node(NULL, 0);
	queue->tail = queue_node(NULL, 0);
	queue->head->next = queue->tail;
	queue->tail->prev = queue->head;
	return (queue);
}

t_qnode		*queue_dry_node(void *data, size_t size)
{
	t_qnode *node;

	node = ft_memalloc(sizeof(t_qnode));
	node->blob = data;
	node->size = size;
	return (node);
}

void		queue_iter(t_queue *q, bool from_head, void (*f)(t_qnode *))
{
	t_qnode *walk;

	if (!q || q->head->next == q->tail)
		return ;
	walk = from_head ? q->head->next : q->tail->prev;
	while (walk != (from_head ? q->tail : q->head))
	{
		(*f)(walk);
		walk = from_head ? walk->next : walk->prev;
	}
}

void		queue_iteri(t_queue *q, bool from_head,
							void (*f)(t_qnode *, size_t))
{
	t_qnode *walk;
	size_t	i;

	if (!q || q->head->next == q->tail)
		return ;
	i = 0;
	walk = from_head ? q->head->next : q->tail->prev;
	while (walk != (from_head ? q->tail : q->head))
	{
		(*f)(walk, i++);
		walk = from_head ? walk->next : walk->prev;
	}
}
