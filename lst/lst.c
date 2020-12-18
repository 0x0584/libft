/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:12:11 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:56:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst		lst_alloc(void (*del)(void *blob))
{
	t_lst lst;

	lst = malloc(sizeof(struct s_lst));
	lst->head = lst_node(NULL, 0, false);
	lst->tail = lst_node(NULL, 0, false);
	lst->head->prev = NULL;
	lst->head->next = lst->tail;
	lst->tail->prev = lst->head;
	lst->tail->next = NULL;
	lst->size = 0;
	lst->del = del;
	return (lst);
}

void		lst_del_with(t_lst *alst, void (*del)(void *blob))
{
	t_lstnode	walk;
	t_lstnode	tmp;
	t_lst		lst;

	if (!del || !alst || !(lst = *alst))
		return ;
	walk = lst->head->next;
	while (walk != lst->tail)
	{
		tmp = walk;
		walk = walk->next;
		lst_node_del_with(&tmp, del);
	}
	lst_node_del_with(&lst->head, del);
	lst_node_del_with(&lst->tail, del);
	free(lst);
	*alst = NULL;
}

void		lst_del(t_lst *alst)
{
	if (alst && *alst)
		lst_del_with(alst, (*alst)->del);
}

void		lst_free(void *lst)
{
	t_lst tmp;

	if ((tmp = lst))
		lst_del(&tmp);
}
