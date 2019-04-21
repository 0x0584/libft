/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumb_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:40:07 by archid-           #+#    #+#             */
/*   Updated: 2019/04/21 04:02:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dumb_realloc(void **ptr, size_t old, size_t new)
{
	void *mem;
	void *tmp;

	if (!(mem = ALLOC(void *, new)))
		return (NULL);
	(void)ft_memcpy(mem, ptr, old);
	tmp = *ptr;
	free(*ptr);
	return (*ptr = mem);

}
