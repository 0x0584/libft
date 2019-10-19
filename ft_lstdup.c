/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:42:35 by archid-           #+#    #+#             */
/*   Updated: 2019/10/19 13:57:55 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list *lst)
{
	t_list *duped;
	t_list *walk;

	duped = NULL;
	if (lst)
	{
		duped = ft_lstnew(lst->content, lst->content_size);
		walk = duped;
		while (lst->next)
		{
			lst = lst->next;
			walk->next = ft_lstnew(lst->content, lst->content_size);
			walk = walk->next;
		}
	}
	return (duped);
}
