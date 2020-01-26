/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:03:10 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:03:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void		queue_swap_halfs(t_queue *head_queue, t_queue *tail_queue,
								t_qnode *head_split, t_qnode *tail_split)
{
	t_qnode *tmp;
	t_qnode *head;
	t_qnode *tail;

	if (!head_queue || !tail_queue || !head_split || !tail_split
			|| head_split == head_queue->tail
		|| tail_split == tail_queue->head)
		return ;
	tmp = head_queue->head;
	head_queue->head = tail_queue->head;
	tail_queue->head = tmp;
	head = tail_split->prev;
	tail = head_split->next;
	head_split->next = tail_split;
	tail_split->prev = head_split;
	head->next = tail;
	tail->prev = head;
}

t_qnode		**queue_as_array(t_queue *q, bool from_head, size_t *sz)
{
	t_qnode **array;
	t_qnode *walk;
	size_t	size;

	if (!q)
		return (NULL);
	size = 0;
	array = malloc((queue_size(q) + 1) * sizeof(t_qnode *));
	walk = from_head ? QFIRST(q) : QLAST(q);
	while (walk != (from_head ? QTAIL(q) : QHEAD(q)))
	{
		array[size++] = walk;
		walk = from_head ? walk->next : walk->prev;
	}
	array[size] = NULL;
	if (sz)
		*sz = size;
	return (array);
}

size_t		queue_size(t_queue *q)
{
	size_t	size;
	t_qnode *walk;

	if (!q || q->head->next == q->tail)
		return (0);
	size = 0;
	walk = q->head->next;
	while (walk != q->tail)
	{
		size++;
		walk = walk->next;
	}
	return (size);
}
