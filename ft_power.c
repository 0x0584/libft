/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:32:10 by archid-           #+#    #+#             */
/*   Updated: 2019/04/08 10:35:06 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int x, int y)
{
	long int result;

	result = 1;
	if (y == 0)
		return (result);
	while (y--)
		result *= x;
	return ((int)result);
}
