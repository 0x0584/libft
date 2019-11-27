/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:36:42 by archid-           #+#    #+#             */
/*   Updated: 2019/11/27 10:33:24 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static bool	check_node(t_ps ps, t_ps_node *node)
{
	t_lst		walk;

	walk = ps->stack;
	while (walk && (AS_NODE(walk->content)->value != node->value))
		walk = walk->next;
	return (walk == NULL);
}

static long	get_numeric_val(char *str)
{
	size_t		i;
	long		val;

	if (!SAFE_PTRVAL(str))
		return (LONG_MIN);
	i = (ft_strchr("+-", *str) ? 1 : 0);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (LONG_MIN);
	}
	val = ft_atol(str);
	return (val >= INT_MIN && val <= INT_MAX ? val : LONG_MIN);
}

t_ps		read_args(int ac, char **av)
{
	t_ps_node	node;
	t_ps		ps;
	long		val;
	int			i;

	if (ac < 2 || !SAFE_PTRVAL(av))
		return (NULL);
	i = 1;
	ps = ps_alloc('a', (size_t)(ac - 1));
	ps->len = ac;
	while (i < ac)
	{
		val = get_numeric_val(av[i++]);
		node = (t_ps_node){(int)val, 0, 0};
		if (val == LONG_MIN || !check_node(ps, &node))
		{
			ft_putendl_fd("ERROR", 2);
			ps_del(&ps);
			break ;
		}
		ft_lstpush(&ps->stack, ft_lstnew(&node, sizeof(t_ps_node)));
	}
	return (ps);
}

t_lst		read_input(void)
{
	char		*buff;
	t_lst		ops;
	t_op		op;
	bool		flag;
	char		bar[4];

	ops = NULL;
	flag = true;
	while (flag && gnl(0, &buff))
	{
		flag = (ft_strlen(ft_strncpy(bar, buff, 3)) >= 2);
		ft_strdel(&buff);
		ft_striter(bar, striter_tolower);
		op = OP_INIT(OP_NA, APPLY_NA);
		if (flag && (flag = op_isvalid(bar, &op)))
			ft_lstpush(&ops, ft_lstnew(&op, sizeof(t_op)));
	}
	ft_strdel(&buff);
	if (!flag)
		ft_lstdel(&ops, lstdel_helper);
	return (ops);
}

void		take_best_ops(t_lst *opt, t_lst *tmp)
{
	if (*opt == NULL)
		*opt = *tmp;
	else if (ft_lstlen(*tmp) < ft_lstlen(*opt))
	{
		ft_lstdel(opt, lstdel_helper);
		*opt = *tmp;
	}
	else
		ft_lstdel(tmp, lstdel_helper);
}
