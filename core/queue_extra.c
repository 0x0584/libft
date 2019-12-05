/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:27:45 by archid-           #+#    #+#             */
/*   Updated: 2019/12/05 16:42:21 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

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

void		queue_iter_back(t_queue *q, void (*dump)(t_qnode *))
{
	t_qnode *walk;

	walk = q->tail->prev;

	while (walk != q->head)
	{
		dump(walk);
		walk = walk->prev;
	}
}
