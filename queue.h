/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:34:27 by archid-           #+#    #+#             */
/*   Updated: 2020/01/24 01:20:04 by archid-          ###   ########.fr       */
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

typedef struct s_queue_node		t_qnode;
struct							s_queue_node
{
	void				*blob;
	size_t				size;
	struct s_queue_node	*next;
	struct s_queue_node	*prev;
};

/*
** always head -> tail
** inserting nodes between head and tail
*/

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
t_qnode 						*queue_deq(t_queue *queue);
t_qnode							*queue_pop(t_queue *queue);
void							queue_push_front(t_queue *queue, t_qnode *node);
t_qnode							*queue_last(t_queue *q);
void							queue_swap_halfs(t_queue *head_queue,
												 t_queue *tail_queue,
												 t_qnode *head_split,
												 t_qnode *tail_split);

void							queue_node_del_next(t_queue *q, t_qnode *node,
														void (*del)(void *,
																	size_t));
void							queue_mergesort(t_queue **q,
													int (*cmp)(t_qnode *,
																t_qnode *));
bool							queue_isempty(t_queue *q);
t_qnode							**queue_as_array(t_queue *q,
												 bool from_head, size_t *sz);

#endif
