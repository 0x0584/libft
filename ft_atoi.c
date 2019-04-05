/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:23:59 by archid-           #+#    #+#             */
/*   Updated: 2019/04/04 00:41:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	size_t	len;
	int		result;
	int		sign;
	char	*str;

	if (s[0] == '\0')
		return (0);
	sign = 1;
	str = (char *)s;
	while (ft_iswhitespace(*str) || *str >= 127)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	result = 0;
	while (ft_isdigit(*str))
		result += ft_power(10, --len) * (*str++ - '0');
	return (result * sign);
}
