/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:14:42 by archid-           #+#    #+#             */
/*   Updated: 2023/01/14 19:11:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	striter_tolower(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
}

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	i = 0;
	while (s && s[i] && f)
		(*f)(&s[i++]);
}
