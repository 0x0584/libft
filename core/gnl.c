/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2020/12/16 12:31:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_status(t_cache *cache, char **line, ssize_t nbytes)
{
	bool ret;

	if (nbytes < 0)
		return (-1);
	else if (has_line(cache, line))
		return (true);
	if ((ret = (cache->length != cache->index)))
		*line = ft_strdup(cache->base + cache->index);
	cache->index = cache->length;
	return (ret);
}

int			read_cache(t_cache *cache, char **line)
{
	ssize_t		nbytes;
	ssize_t		i;
	bool		nl;

	nl = false;
	while (!nl && (nbytes = read(cache->fd, g_buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		if (cache->length + nbytes > cache->size)
			cache_grow(cache);
		while (i < nbytes)
		{
			if (g_buff[i] == '\n')
				nl = true;
			cache->base[cache->length++] = g_buff[i++];
		}
	}
	cache->base[cache->length] = '\0';
	return (read_status(cache, line, nbytes));
}

int			gnl(const int fd, char **line)
{
	t_cache *cache;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(cache = cache_alloc(fd)))
		return (-1);
	*line = NULL;
	return (has_line(cache, line) ? 1 : read_cache(cache, line));
}

void		gnl_cleanup(void)
{
	size_t	i;
	t_cache *cache;

	if (g_buff)
		ft_strdel(&g_buff);
	i = 0;
	while (i < CACHE_SIZE)
	{
		cache = &g_cache[i++];
		if (cache->base)
			ft_strdel(&cache->base);
		cache->fd = -1;
		cache->size = 0;
		cache->index = 0;
		cache->length = 0;
	}
}

int			gnl_clean(const int fd)
{
	size_t	i;
	t_cache *cache;
	bool	flag;

	if (fd < 0)
		return (-1);
	if (g_buff)
		ft_strdel(&g_buff);
	i = 0;
	flag = false;
	while (!flag && i < CACHE_SIZE)
	{
		cache = &g_cache[i++];
		if (cache->fd != fd)
			continue;
		ft_strdel(&cache->base);
		cache->fd = -1;
		cache->size = 0;
		cache->index = 0;
		cache->length = 0;
		flag = true;
	}
	return (flag);
}
