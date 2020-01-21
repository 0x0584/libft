/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:11 by archid-           #+#    #+#             */
/*   Updated: 2020/01/19 16:51:32 by archid-          ###   ########.fr       */
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
	while (walk != q->tail)
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
	queue->head->next->prev = node;
	node->prev = queue->head;
	queue->head->next = node;
}

t_qnode 	*queue_pop(t_queue *queue)
{
	t_qnode *node;

	if (!queue || queue->head->next == queue->tail)
		return (NULL);
	node = queue->tail->prev;
	queue->tail->prev = node->prev;
	node->prev->next = queue->tail;
	return (node);
}

void queue_dry_del_helper(void *blob, size_t size)
{
	(void)blob;
	(void)size;
	return ;
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

void		queue_iteri(t_queue *q, bool from_head, void (*f)(t_qnode *, size_t))
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

void		print_int_node(t_qnode *node)
{
	if (!node)
		return ;
	ft_printf("%d ", *(int *)node->blob);

}

void		queue_del_helper(void *blob, size_t size)
{
	if (size)
		free(blob);
}
/*
int			main(int ac, char **av)
{
	int		i;
	int		val;
	t_queue *q;
	t_qnode *node;

	if (ac == 1)
		return -1;
	i = 1;
	q = queue_init();
	while (i < ac)
	{
		val = ft_atoi(av[i++]);
		queue_enq(q, queue_node(&val, sizeof(int)));
		queue_iter(q, print_int_node);
		ft_printf("\nsize >> %zu\n", queue_size(q));
	}
	ft_putchar('\n');
	while(queue_size(q))
	{
		queue_iter(q, print_int_node);
		node = queue_deq(q);
		queue_node_del(&node, queue_del_helper);
		ft_putchar('\n');
	}
	ft_printf("head: %p head next: %p | tail:%p tail prev: %p\n",
			  q->head, q->head->next, q->tail, q->tail->prev);
	ft_printf(" /// ");
	system("sleep 100");
	i = 1;
	while (i < ac)
	{
		val = ft_atoi(av[i++]);
		queue_enq(q, queue_node(&val, sizeof(int)));
		queue_iter(q, print_int_node);
		ft_printf("\nsize >> %zu\n", queue_size(q));
	}
	queue_del(&q, queue_del_helper);
	return 0;
}
*/

t_qnode *queue_last(t_queue *q)
{
	if (!q || !queue_size(q))
		return NULL;
	return q->tail->prev->blob;
}

void	queue_swap_halfs(t_queue *head_queue, t_queue *tail_queue,
							t_qnode *head_split, t_qnode *tail_split)
{
	t_qnode *tmp;
	t_qnode *head;
	t_qnode *tail;

	if (!head_queue || !tail_queue || !head_split || !tail_split
			|| head_split == head_queue->tail || tail_split == tail_queue->head)
		return ;

	/* swap the tails */
	tmp = head_queue->head;
	head_queue->head = tail_queue->head;
	tail_queue->head = tmp;

	/* keeping track of head split */
	head = tail_split->prev;
	tail = head_split->next;


	/* merge tail split */
	head_split->next = tail_split;
	tail_split->prev = head_split;

	/* merge head split */
	head->next = tail;
	tail->prev = head;
}

void	queue_node_del_next(t_queue *q, t_qnode *node,
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

/* lower priorities are at the head */
void queue_penq(t_queue *queue, t_qnode *node,
					bool (*cmp)(t_qnode *, t_qnode *))
{
	t_qnode *walk;
	bool	inserted;

	if (!queue || !node)
		return ;
	else if (!cmp)
	{
		queue_enq(queue, node);
		return ;
	}
	inserted = false;
	walk = queue->head->next;
	while (walk != queue->tail)
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
