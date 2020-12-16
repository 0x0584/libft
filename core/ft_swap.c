/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 03:52:32 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:43:25 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_swap(void *u, void *v, size_t size)
{
	void *tmp;

	if (!(tmp = ft_calloc(1, size)))
		return (0);
	ft_memcpy(tmp, v, size);
	ft_memcpy(v, u, size);
	ft_memcpy(u, tmp, size);
	return (1);
}
