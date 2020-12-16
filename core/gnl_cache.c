/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cache.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:32:05 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 12:31:56 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*g_buff = NULL;
bool	g_cache_ready = false;
t_cache g_cache[CACHE_SIZE];

void			cache_grow(t_cache *cache)
{
	char	*base;
	size_t	size;

	size = cache->size * 1.5;
	base = malloc(size + 1);
	ft_strncpy(base, cache->base + cache->index, size);
	ft_strchange(&cache->base, base);
	cache->size = size;
	cache->length -= cache->index;
	cache->index = 0;
}

void			cache_setup(void)
{
	int		i;

	if (g_cache_ready)
		return ;
	i = 0;
	while (i < CACHE_SIZE)
		g_cache[i++].fd = -1;
	g_cache_ready = (true);
}

static t_cache	*cache_init(t_cache *cache, const int fd)
{
	cache->fd = fd;
	cache->base = ft_memalloc(BUFF_SIZE + 1);
	cache->size = BUFF_SIZE;
	cache->index = 0;
	cache->length = 0;
	return (cache);
}

t_cache			*cache_alloc(const int fd)
{
	t_cache		*cache;
	int			i;
	int			j;

	if (!g_buff)
		g_buff = malloc(BUFF_SIZE);
	cache_setup();
	i = 0;
	j = -1;
	while (i < CACHE_SIZE)
	{
		cache = &g_cache[i];
		if (cache->fd == fd)
			return (cache);
		else if (j == -1 && cache->fd < 0)
			j = i;
		i++;
	}
	return (j < 0 ? NULL : cache_init(&g_cache[j], fd));
}

bool			has_line(t_cache *cache, char **line)
{
	char		*nl;

	if (!(nl = ft_strchr(cache->base + cache->index, '\n')))
		return (false);
	*nl = '\0';
	*line = ft_strdup(cache->base + cache->index);
	cache->index = nl - cache->base + 1;
	return (true);
}
