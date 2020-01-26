/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:34:27 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:02:34 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "../libft/libft.h"
# include <limits.h>

# define QNODE_AS(t, e)			((t *)e->blob)

# define QHEAD(q)				(q)->head
# define QTAIL(q)				(q)->tail

# define QFIRST(q)				(q)->head->next
# define QLAST(q)				(q)->tail->prev

# define QNODE_GETNEXT(q, e)	((e)->next != QTAIL(q) ? (e)->next : NULL)
# define QNODE_GETPREV(q, e)	((e)->prev != QHEAD(q) ? (e)->prev : NULL)

# define QUEUE_ISEMPTY(q)		(!(q) || QFIRST(q) == QTAIL(q))

typedef struct s_queue_node		t_qnode;
struct							s_queue_node
{
	void				*blob;
	size_t				size;
	struct s_queue_node	*next;
	struct s_queue_node	*prev;
};

typedef struct s_queue			t_queue;
struct							s_queue
{
	struct s_queue_node *head;
	struct s_queue_node *tail;
	void				(*del)(void *, size_t);
};

t_qnode							*queue_node(void *blob, size_t size);
void							queue_del_helper(void *blob, size_t size);
void							queue_node_del(t_qnode **a_node,
												void (*del)(void *, size_t));

t_qnode							*queue_dry_node(void *data, size_t size);
void							queue_dry_del_helper(void *blob, size_t size);

t_queue							*queue_init(void);
void							queue_iter(t_queue *q, bool from_head,
											void (*f)(t_qnode *));
void							queue_iteri(t_queue *q, bool from_head,
											void (*f)(t_qnode *, size_t));
size_t							queue_size(t_queue *q);
void							queue_del(t_queue **a_queue,
											void (*del)(void *, size_t));
void							queue_enq(t_queue *queue, t_qnode *node);
void							queue_penq(t_queue *queue, t_qnode *node,
											bool (*cmp)(t_qnode *, t_qnode *));
t_qnode							*queue_deq(t_queue *queue);
t_qnode							*queue_pop(t_queue *queue);
void							queue_push_front(t_queue *queue, t_qnode *node);
void							queue_swap_halfs(t_queue *hq, t_queue *tq,
													t_qnode *hs, t_qnode *ts);

void							queue_node_del_next(t_queue *q, t_qnode *node,
														void (*del)(void *,
																	size_t));
void							queue_mergesort(t_queue **q,
													int (*cmp)(t_qnode *,
																t_qnode *));
t_qnode							**queue_as_array(t_queue *q, bool from_head,
													size_t *sz);

#endif
