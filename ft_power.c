/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:32:10 by archid-           #+#    #+#             */
/*   Updated: 2019/04/01 20:46:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a dump recursive function that returns the y-th power of x...
 */

#include "libft.h"

int		ft_power(int x, int y)
{
	if (y <= 0)
		return (1);
	else if (y == 1)
		return (x);
	else
		return (x * ft_power(x, y - 1));
}
