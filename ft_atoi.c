/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:23:59 by archid-           #+#    #+#             */
/*   Updated: 2019/04/02 01:06:38 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	size_t	len;
	int		result;
	int		sign;
	char	*str;

	sign = 1;
	len = 0;
	result = 0;
	str = (char *)s;
	while (ft_iswhitespace(*str) || *str >= 127)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(str[len]))
		len++;
	while (ft_isdigit(*str))
		result += ft_power(10, --len) * (*str++ - '0');
	return (result * sign);
}
