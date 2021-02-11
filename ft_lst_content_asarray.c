/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_content_asarray.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:48:31 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:37:07 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			**ft_lst_content_asarray(t_list *head, size_t *size)
{
	void	**arr;
	size_t	sz;
	t_list	*walk;

	if (!(arr = ft_calloc(ft_lstlen(head) + 1, sizeof(void *))))
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
