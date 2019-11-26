/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:41:51 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 19:15:09 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	op_dump(t_op op)
{
	char *prefix;
	char *suffix;

	prefix = "psrr";
	suffix = "ab";
	ft_printf("%c", prefix[op.op]);
	if (op.op == OP_RROT)
		ft_printf("%c", 'r');
	if (op.which != APPLY_ON_BOTH)
		ft_printf("%c", suffix[op.which]);
	else if (op.op == OP_ROT || op.op == OP_RROT)
		ft_printf("%c", 'r');
	else
		ft_printf("%c", 's');
	ft_printf("\n");
}

bool	op_isvalid(char const *str, t_op *op)
{
	if (str[0] == 'p' && (str[1] == 'a' || str[1] == 'b') && !str[2])
		*op = OP_INIT(OP_PUSH, str[1] == 'b');
	else if (str[0] == 's' && !str[2])
	{
		if (str[1] == 'a' || str[1] == 'b')
			*op = OP_INIT(OP_SWAP, str[1] == 'b');
		else if (str[1] == 's')
			*op = OP_INIT(OP_SWAP, APPLY_ON_BOTH);
	}
	else if (str[0] == 'r')
	{
		op->which = APPLY_ON_BOTH;
		if (str[1] == 'r' && (str[2] == 'a' || str[2] == 'b'))
			*op = OP_INIT(OP_RROT, str[2] == 'b');
		else if (str[1] == 'a' || str[1] == 'b')
			*op = OP_INIT(OP_ROT, str[1] == 'b');
		else if (str[1] == 'r' && str[2] == 'r')
			op->op = OP_RROT;
		else if (str[1] == 'r' && !str[2])
			op->op = OP_ROT;
	}
	return (OP_IS_GOOD(op));
}

bool		op_apply(t_op op, t_ps foo, t_ps bar)
{
	if (op.op == OP_PUSH)
		return (op_dopsh(!op.which ? foo : bar, !op.which ? bar : foo));
	if (op.op == OP_SWAP)
	{
		if (op.which != APPLY_ON_BOTH)
			return (op_doswp(!op.which ? foo : bar));
		return (op_doswp(foo) && op_doswp(bar));
	}
	if (op.op == OP_ROT || op.op == OP_RROT)
	{
		if (op.which != APPLY_ON_BOTH)
			return (op_dorot(!op.which ? foo : bar, op.op == OP_ROT));
		return (op_dorot(foo, op.op == OP_ROT)
					&& op_dorot(bar, op.op == OP_ROT));
	}
	return (false);
}

t_lst	op_as_node(int op, int which)
{
	t_op o;

	o.op = op;
	o.which = which;
	return (ft_lstnew(&o, sizeof(t_op)));
}

void	op_save(t_op op, t_lst *ops, t_ps a, t_ps b)
{
	op_apply(op, a, b);
	ft_lstpush(ops, ft_lstnew(&op, sizeof(t_op)));
}
