/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:54:41 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 11:27:35 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*helper_merge(t_list *left, t_list *right,
								int (*cmp)(t_list *, t_list *))
{
	t_list	*root;
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

static void		helper_halfsplit(t_list *root, t_list **ahead,
									t_list **atail)
{
	t_list *foo;
	t_list *bar;

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

void			ft_lst_mergesort(t_list **alst, int (cmp)(t_list *, t_list *))
{
	t_list *left;
	t_list *right;

	if (!alst || !*alst || !(*alst)->next)
		return ;
	helper_halfsplit(*alst, &left, &right);
	ft_lst_mergesort(&left, cmp);
	ft_lst_mergesort(&right, cmp);
	*alst = helper_merge(left, right, cmp);
}
