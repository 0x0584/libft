/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:42:23 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 18:25:45 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "op.h"
#include "reader.h"

int		main(int argc, char *argv[])
{
    t_ps	ps_a, ps_b;
	t_lst	ops;
	t_lst	walk;

	if (!(ps_a = read_args(argc, argv)))
		return (EXIT_FAILURE);
	ps_b = ps_alloc('B', ps_a->size);
	if ((ops = read_input()))
	{
		walk = ops;
		while (walk)
		{
			op_apply(*(t_op *)walk->content, ps_a, ps_b);
			walk = walk->next;
		}
		ft_putendl(ps_issorted(ps_a, ps_b) ? "OK" : "KO");
	}
	else
		ft_putendl_fd("ERROR", 2);
	ft_lstdel(&ops, lstdel_helper);
	ps_del(&ps_a);
	ps_del(&ps_b);
    return (0);
}
