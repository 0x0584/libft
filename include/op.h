/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:16:37 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 19:16:01 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "ps.h"

typedef struct	s_op
{
	enum e_which_stack
	{
		APPLY_ON_A, APPLY_ON_B,
		APPLY_ON_BOTH, APPLY_NA = -1
  	}		which;
	enum e_op
	{
		OP_PUSH, OP_SWAP, OP_ROT,
		OP_RROT, OP_NA = -1,
	}		op;
}				t_op;

# define OP_INIT(op, which)		(t_op){(which), (op)}
# define OP_IS_GOOD(op)			(op->op != OP_NA && op->which != APPLY_NA)

bool	op_apply(t_op op, t_ps foo, t_ps bar);
bool	op_isvalid(char const *str, t_op *op);
void	op_save(t_op op, t_lst *ops, t_ps a, t_ps b);
void	op_dump(t_op op);

bool	op_dopsh(t_ps dest, t_ps src);
bool	op_doswp(t_ps stack);
bool	op_dorot(t_ps stack, bool is_up);

void	helper_op_dump(t_lst e);
void	take_best_ops(t_lst *opt, t_lst *tmp);
void	append_ops(t_ps a, t_ps b, t_lst *ops, t_lst *new);
t_lst	op_as_node(int op, int which);

#endif
