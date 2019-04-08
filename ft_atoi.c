/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:23:59 by archid-           #+#    #+#             */
/*   Updated: 2019/04/08 10:32:09 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	long	result;
	int		sign;
	char	*str;
	size_t	len;

	if (s[0] == '\0')
		return (0);
	sign = 1;
	str = (char *)s;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	result = 0;
	while (ft_isdigit(*str))
	{
		if (result > INT_VALMAX || result < INT_VALMIN)
			return (sign == 1 ? -1 : 0);
		result += ft_power(10, --len) * (*str++ - '0');
	}
	return (result * sign);
}
