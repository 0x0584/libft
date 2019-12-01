/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:27:45 by archid-           #+#    #+#             */
/*   Updated: 2019/12/01 19:53:35 by archid-          ###   ########.fr       */
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
