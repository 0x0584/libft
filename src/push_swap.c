/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:18:20 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 19:17:02 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "reader.h"

t_lst	compress_ops(t_lst ops)
{
	t_lst	walk;
	t_lst	tmp;
	t_op	*op[2];

	walk = ops;
	while (walk && walk->next)
	{
		op[0] = walk->content;
		op[1] = walk->next->content;
		if (((op[0]->op == OP_ROT && op[1]->op == OP_ROT)
				|| (op[0]->op == OP_RROT && op[1]->op == OP_RROT)
				|| (op[0]->op == OP_SWAP && op[1]->op == OP_SWAP))
			&& ((op[0]->which == APPLY_ON_A && op[1]->which == APPLY_ON_B)
				|| (op[1]->which == APPLY_ON_A && op[0]->which == APPLY_ON_B)))
		{
			tmp = walk->next;
			walk->next = walk->next->next;
			op[0]->which = APPLY_ON_BOTH;
			ft_lstdelone(&tmp, lstdel_helper);
		}
		walk = walk->next;
	}
	return (ops);
}

t_lst	gen_ops(t_ps_array arr, t_ps b, int b_rots, t_ps_node *node)
{
	t_lst	ops;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ops = NULL;
	node->a_cost = binary_search_range(node->value, arr.base,
										0, arr.size - 1);
	if (b_rots > (int)(b->len - 1) / 2)
		b_rots -= (int)b->len;
	node->b_cost = b_rots;
	while (i < (int)ABS(node->a_cost) || j < (int)ABS(node->b_cost))
	{
		if (i++ < (int)ABS(node->a_cost))
			ft_lstpush(&ops, op_as_node(node->a_cost > 0 ? OP_ROT : OP_RROT,
											APPLY_ON_A));
		if (j++ < (int)ABS(node->b_cost))
			ft_lstpush(&ops, op_as_node(node->b_cost > 0 ? OP_ROT : OP_RROT,
											APPLY_ON_B));
	}
	ft_lstpush(&ops, op_as_node(OP_PUSH, APPLY_ON_A));
	return (compress_ops(ops));
}

void	adjust_stack(t_ps a, t_lst *ops)
{
	t_ps_array	arr;
	int			n_rots;
	int			min;
	int			max;
	bool		is_up;

	if (ps_issorted(a, NULL))
		return ;
	is_up = true;
	arr = ps_vals_asarray(a);
	min = binary_search_min(arr.base, 0, arr.size - 1);
	max = (min == 0) ? (int)arr.size - 1 : min - 1;
	n_rots = (int)arr.size - 1 - min - 1;
	if ((is_up = (n_rots >= 0)))
		n_rots = max + 1;
	else
		n_rots = ABS(n_rots);
	while (n_rots--)
		op_save(OP_INIT(is_up ? OP_ROT : OP_RROT, APPLY_ON_A),
				ops, a, NULL);
	free(arr.base);
}

void	push_swap(t_ps a, t_ps b, t_lst *ops)
{
	t_ps_array	arr;
	t_lst		walk;
	t_lst		tmp_ops[2];
	int			b_rots;

	tmp_ops[0] = NULL;
	while (b->len)
	{
		b_rots = 0;
		walk = b->stack;
		arr = ps_vals_asarray(a);
 		while (walk)
		{
			tmp_ops[1] = gen_ops(arr, b, b_rots++, walk->content);
			take_best_ops(&tmp_ops[0], &tmp_ops[1]);
			walk = walk->next;
		}
		free(arr.base);
		append_ops(a, b, ops, &tmp_ops[0]);
	}
}

int		main(int argc, char **argv)
{
	t_ps ps_a;
	t_ps ps_b;
	t_lst ops;

	if (!(ps_a = read_args(argc, argv)) || !(ps_b = ps_alloc('b', ps_a->size)))
		return EXIT_FAILURE;
	ops = NULL;
	if (ps_issorted(ps_a, ps_b))
		return (EXIT_SUCCESS);
	else if (ps_a->size <= FEW_ELEMENTS)
		ps_sort_few(ps_a, ps_b, &ops);
	else
	{
		while (ps_a->len - FEW_ELEMENTS)
			op_save(OP_INIT(OP_PUSH, APPLY_ON_B), &ops, ps_a, ps_b);
		push_swap(ps_a, ps_b, &ops);
		adjust_stack(ps_a, &ops);
	}
	ft_lstiter(ops, helper_op_dump);
	ft_lstdel(&ops, lstdel_helper);
	ps_del(&ps_a);
	ps_del(&ps_b);
	return (EXIT_SUCCESS);
}
