/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:54:41 by archid-           #+#    #+#             */
/*   Updated: 2019/11/27 10:54:54 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst		helper_merge(t_lst left, t_lst right,
									int (cmp)(t_lst, t_lst))
{
	t_lst	root;
	bool	sort_on_left;

	if (!left || !right)
		return (!left ? right : left);
	sort_on_left = cmp(left, right) > 0;
	root = sort_on_left ? left : right;
	root->next = helper_merge(sort_on_left ? left->next : left,
								sort_on_left ? right : right->next,
								cmp);
	return (root);
}

static void			helper_halfsplit(t_lst root, t_lst *ahead,
										t_lst *atail)
{
	t_lst foo;
	t_lst bar;

	bar = root;
	foo = root->next;
	while (foo)
	{
		foo = foo->next;
		if (foo)
		{
			bar = bar->next;
			foo = foo->next;
		}
	}
	*ahead = root;
	*atail = bar->next;
	bar->next = NULL;
}

void				ft_lst_mergesort(t_lst *alst, int (cmp)(t_lst, t_lst))
{
	t_lst left;
	t_lst right;

	if (!alst || !*alst || !(*alst)->next)
		return ;
	helper_halfsplit(*alst, &left, &right);
	ft_lst_mergesort(&left, cmp);
	ft_lst_mergesort(&right, cmp);
	*alst = helper_merge(left, right, cmp);
}
