/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:05:21 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 19:17:20 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

bool	op_dopsh(t_ps dest, t_ps src)
{
	if (!dest || !src || !src->len || dest->len == dest->size + 1)
		return (false);
	ft_lstadd(&dest->stack, ft_lstpeek(&src->stack));
	src->len--;
	dest->len++;
	return (true);
}

bool	op_doswp(t_ps ps)
{
	t_lst foo;
	t_lst bar;

	if (!ps || ps->len < 2)
		return (false);
	foo = ft_lstpeek(&ps->stack);
	bar = ft_lstpeek(&ps->stack);
	ft_lstadd(&ps->stack, foo);
	ft_lstadd(&ps->stack, bar);
	return (true);
}

bool	op_dorot(t_ps ps, bool is_up)
{
	t_lst node;

	if (!ps || ps->len < 2)
		return (false);
	if (is_up)
		node = ft_lstpeek(&ps->stack);
	else
		node = ft_lstpop(&ps->stack);
	if (is_up)
		ft_lstpush(&ps->stack, node);
	else
		ft_lstadd(&ps->stack, node);
	return (true);
}

void	helper_op_dump(t_lst e)
{
	t_op *op;

	op = e->content;
	op_dump(*op);
}

void	append_ops(t_ps a, t_ps b, t_lst *ops, t_lst *new)
{
	t_lst walk;

	if (!SAFE_PTRVAL(new))
		return ;
	walk = *new;
	while (walk)
	{
		op_save(*(t_op *)walk->content, ops, a, b);
		walk = walk->next;
	}
	ft_lstdel(new, lstdel_helper);
}
