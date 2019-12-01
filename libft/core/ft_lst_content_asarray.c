/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_content_asarray.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:48:31 by archid-           #+#    #+#             */
/*   Updated: 2019/11/27 10:55:11 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			**ft_lst_content_asarray(t_lst head, size_t *size)
{
	void	**arr;
	size_t	sz;
	t_lst	walk;

	if (!(arr = ALLOC(void **, ft_lstlen(head) + 1, sizeof(void *))))
		return (NULL);
	walk = head;
	sz = 0;
	while (walk)
	{
		arr[sz++] = walk->content;
		walk = walk->next;
	}
	if (size)
		*size = sz;
	return (arr);
}
