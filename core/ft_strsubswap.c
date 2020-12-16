/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:06:38 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 13:42:35 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsubswap(char **astr, const char *s1, const char *s2)
{
	if (!(astr && *astr))
		return ;
	ft_strreplace(astr, s1, s2);
	ft_strreplace(astr, s2, s1);
}
