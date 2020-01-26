/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_mergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:12:08 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 00:56:20 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static t_queue	*helper_merge(t_queue **left, t_queue **right,
								int (*cmp)(t_qnode *, t_qnode *))
{
	t_queue *root;
	t_qnode *tmp;
	t_queue **to_free;
	int		sort;

	root = NULL;
	if (!QUEUE_ISEMPTY(*right) && !QUEUE_ISEMPTY(*left))
	{
		sort = cmp(QFIRST(*left), QFIRST(*right));
		tmp = sort < 0 ? queue_deq(*left) : queue_deq(*right);
		if (!(root = helper_merge(left, right, cmp)))
			return (NULL);
		queue_push_front(root, tmp);
	}
	else if (QUEUE_ISEMPTY(*left) || QUEUE_ISEMPTY(*right))
	{
		root = QUEUE_ISEMPTY(*left) ? *right : *left;
		to_free = QUEUE_ISEMPTY(*left) ? left : right;
		ft_free(free, QHEAD(*to_free), QTAIL(*to_free), *to_free, NULL);
		*to_free = NULL;
	}
	return (root);
}

static void		helper_halfsplit(t_queue *root, t_queue **left,
									t_queue **right)
{
	t_qnode *foo;
	t_qnode *bar;

	bar = QFIRST(root);
	foo = bar->next;
	while (foo != QTAIL(root))
	{
		foo = foo->next;
		if (foo != QTAIL(root))
		{
			bar = bar->next;
			foo = foo->next;
		}
	}
	(*left) = malloc(sizeof(t_queue));
	(*right) = malloc(sizeof(t_queue));
	(*left)->head = root->head;
	(*left)->tail = queue_node(NULL, 0);
	(*right)->head = queue_node(NULL, 0);
	(*right)->tail = root->tail;
	(*left)->tail->prev = bar;
	(*right)->head->next = bar->next;
	bar->next->prev = (*right)->head;
	bar->next = (*left)->tail;
}

void			queue_mergesort(t_queue **q, int (*cmp)(t_qnode *, t_qnode *))
{
	t_queue *left;
	t_queue *right;
	t_queue *tmp;

	if (!q || !*q || !cmp || QUEUE_ISEMPTY(*q)
			|| !QNODE_GETNEXT(*q, QFIRST(*q)))
		return ;
	helper_halfsplit(*q, &left, &right);
	queue_mergesort(&left, cmp);
	queue_mergesort(&right, cmp);
	tmp = *q;
	*q = helper_merge(&left, &right, cmp);
	ft_free(free, tmp, NULL);
}
