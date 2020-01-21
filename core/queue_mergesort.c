/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_mergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:12:08 by archid-           #+#    #+#             */
/*   Updated: 2020/01/23 21:51:50 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int queue_lex(t_qnode *u, t_qnode *v)
{
	return ft_strcmp(u->blob, v->blob);
}

bool queue_isempty(t_queue *q)
{
	return !q || QFIRST(q) == QTAIL(q);
}


static t_queue *helper_merge(t_queue **left, t_queue **right,
								int (*cmp)(t_qnode *, t_qnode *))
{
	t_queue *root;
	t_qnode *tmp;
	int sort;

	root = NULL;
	if (!queue_isempty(*right) && !queue_isempty(*left))
	{
		sort = cmp(QFIRST(*left), QFIRST(*right));
		tmp = sort < 0 ? queue_deq(*left) : queue_deq(*right);
		if (!(root = helper_merge(left, right, cmp)))
			return NULL;
		queue_push_front(root, tmp);
	}
	else if (*left && queue_isempty(*left))
	{
		root = *right;
		ft_free(free, QHEAD(*left), QTAIL(*left), *left, NULL);
		*left = NULL;
	}
	else if (*right && queue_isempty(*right))
	{
		root = *left;
		ft_free(free, QHEAD(*right), QTAIL(*right), *right, NULL);
		*right = NULL;
	}
	return root;
}

static void			helper_halfsplit(t_queue *root, t_queue **left,
										t_queue **right)
{
	t_queue *l;
	t_queue *r;

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

	l = malloc(sizeof(t_queue));
	r = malloc(sizeof(t_queue));

	l->head = root->head;
	l->tail = queue_node(NULL, 0);

	r->head = queue_node(NULL, 0);
	r->tail = root->tail;

	l->tail->prev = bar;
	r->head->next = bar->next;

	bar->next->prev = r->head;
	bar->next = l->tail;

	*left = l;
	*right = r;
}

void				queue_mergesort(t_queue **q, int (*cmp)(t_qnode *, t_qnode *))
{
	t_queue *left;
	t_queue *right;
	t_queue *tmp;

	if (!q || !*q || !cmp || queue_isempty(*q)
			|| !QNODE_GETNEXT(*q, QFIRST(*q)))
		return ;

	/* ft_printf(">> turn:  %d \n", ++count); */
	/* queue_iter(*q, true, queue_putstr); */
	/* ft_putendl(" ---  "); */

	helper_halfsplit(*q, &left, &right);

	/* ft_putendl(" ------ "); */
	/* queue_iter(left, true, queue_putstr); */
	/* ft_putendl(" // "); */
	/* queue_iter(right, true, queue_putstr); */
	/* ft_putendl(" ------ "); */

	queue_mergesort(&left, cmp);
	queue_mergesort(&right, cmp);

	tmp = *q;
	*q = helper_merge(&left, &right, cmp);

	ft_free(free, tmp, NULL);

	/* ft_printf(">>>> turn:  %d \n", count); */
	/* queue_iter(*q, true, queue_putstr); */
	/* ft_putendl(" ---  "); */


}

/*

int main(int argc, char *argv[])
{
	int i = 1;
    t_queue *q = queue_init();

	while (i < argc)
		queue_enq(q, queue_dry_node(argv[i++], sizeof(char *)));

	queue_mergesort(&q, queue_lex);

	queue_del(&q, queue_dry_del_helper);

    return 0;
}

*/
