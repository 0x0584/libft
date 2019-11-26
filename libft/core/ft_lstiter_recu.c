/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_recu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 05:19:57 by archid-           #+#    #+#             */
/*   Updated: 2019/10/19 18:04:06 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstiter_helper_as_int(t_list *nb)
{
	if (nb)
	{
		ft_putnumber(*((int *)nb->content));
		ft_putendl("");
	}
}

void	ft_lstiter_recu(t_list *lst, void (*f)(t_list *elem))
{
	if (lst)
	{
		if (lst->next)
			ft_lstiter_recu(lst->next, f);
		f(lst);
	}
}
