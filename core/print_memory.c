/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:18:24 by archid-           #+#    #+#             */
/*   Updated: 2021/01/18 12:43:40 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_memory(const void *addr, size_t size)
{
	t_u8	*buff;
	char	*ascii;
	size_t	i;
	size_t	j;
	size_t sz;

	i = 0;
	j = 0;
	sz = 2 * sizeof(t_u64);
	buff = (t_u8 *)addr;
	ascii = ft_calloc(sz + 1, 1);
	while (i < size)
	{
		/* ft_printf("|%02x| %d", buff[i], i); */
		ft_printf("%02x", buff[i]);
		ascii[j++] = ft_isprint(buff[i]) ? buff[i] : '.';
		if ((i + 1) % 2 == 0)
			ft_printf(" ", i);

		if ((i + 1) % 16 == 0)
		{
			ft_putendl(ascii);
			ft_bzero(ascii, sz);
			j = 0;
		}
		i++;
	}
	i %= 16;
	while (i < 16)
	{
		/* ft_printf(" > %d", i); */
		ft_putstr("  ");
		if ((i+1) % 2 == 0)
			ft_putstr(" ");
		i++;
	}
	ascii[j] = '\0';
	ft_putendl(ascii);
}
