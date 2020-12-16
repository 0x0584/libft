/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:42:23 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:38:25 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *foo;

	if (!(alst && *alst))
		return ;
	foo = *alst;
	*alst = NULL;
	(*del)(foo->content, foo->content_size);
	free(foo);
}
