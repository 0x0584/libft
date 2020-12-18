/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_anchors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:48:47 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:50:09 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lstnode	lst_head(t_lst lst)
{
	return (lst ? lst->head : NULL);
}

t_lstnode	lst_tail(t_lst lst)
{
	return (lst ? lst->tail : NULL);
}

t_lstnode	lst_front(t_lst lst)
{
	return (lst_empty(lst) ? NULL : lst_head(lst)->next);
}

t_lstnode	lst_rear(t_lst lst)
{
	return (lst_empty(lst) ? NULL : lst_tail(lst)->prev);
}
