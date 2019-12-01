/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:26:08 by archid-           #+#    #+#             */
/*   Updated: 2019/12/01 19:53:52 by archid-          ###   ########.fr       */
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

void		queue_node_del(t_qnode **a_node, void (*del)(void *, size_t))
{
	if (!a_node || !*a_node)
		return ;
	(*del)((*a_node)->blob, (*a_node)->size);
	free(*a_node);
	*a_node = NULL;
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

size_t		queue_size(t_queue *q)
{
	size_t size;
	t_qnode *walk;

	if (!q || q->head->next == q->tail)
		return (0);
	size = 0;
	walk = q->head->next;
	while (walk)
	{
		size++;
		walk = walk->next;
	}
	return (size);
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
