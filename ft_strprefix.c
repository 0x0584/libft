/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:57:56 by archid-           #+#    #+#             */
/*   Updated: 2021/03/15 14:57:28 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool			ft_strprefix(const char *s, const char *pre)
{
	size_t			i;

	if (!s || !pre)
		return (false);
	i = 0;
	while (s[i] && pre[i] && pre[i] == s[i])
		i++;
	return (!pre[i]);
}

bool			ft_strsuffix(const char *s, const char *suff)
{
	size_t			istr;
	size_t			isuff;

	if (!s || !suff)
		return (false);
	else if (!*suff)
		return (true);
	istr = ft_strlen(s);
	isuff = ft_strlen(suff);
	while (true)
	{
		if (s[istr] != suff[isuff])
			return (false);
		else if (s + istr == s || suff + isuff == suff)
			break ;
		istr--;
		isuff--;
	}
	return (true);
}
