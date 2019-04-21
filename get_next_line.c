/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/21 12:01:39 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FIXME: remove unused headers
*/
/*
** FIXME: remove comments
*/
/*
** FIXME: check the norm
*/
/*
**TODO: improve the code
*/
/*
** FIXEME: reorder e_fuzzbuzz
*/
/*
** FIXME: ft_realloc()
*/

/*
**
*/

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

void	cache_init(t_cache **cache, size_t size)
{
	t_cache *c;

	if (!(c = ALLOC(t_cache *, CACHE_SIZE)))
		return ;

	c->size = size;
	*cache = c;
}

int		cache_alloc(t_cache **cache)
{
	t_cache			*c;

	/* NULL is not accepted as a parameter */
	if (cache == NULL)
		return (failure);
	c = *cache;
	/* if cache is NULL, allocate some memory */
	if (c == NULL)
		cache_init(cache, CACHE_SIZE);
	/* if cache is full, reallocate memory */
	else if (ISFULL_CACHE(c))
	{
		(void)ft_dumb_realloc((void **)cache, c->size, INCR_CACHE_SIZE(c));
		c->size = INCR_CACHE_SIZE(c);
	}
	return (success);
}

int		cache_free(t_cache **cache)
{
	/* free the cache if cache->nl != NULL and reallocte memory for
	 * len(cache->buff) */

	t_cache		*c;

	printf("before '%s' '%s' ", (*cache)->buff, (*cache)->nl);
	c = *cache;
	if (c->nl)
	{
		(void)ft_strcpy(c->buff, c->nl + 1);
		(void)ft_dumb_realloc((void **)&(c->buff),
								c->size, S_SIZE(c->nl + 1));
		c->size = S_SIZE(c->buff);
	}
	printf("after '%s' '%s'\n", (*cache)->buff, (*cache)->nl);
	return (success);
}

int		cache_concat(t_cache *cache, char *buff)
{
	char		*tmp;

	if (!(tmp = ft_strjoin(!cache->buff ? "" : cache->buff, buff)))
		return (failure);
	free(cache->buff);
	cache->buff = tmp;
	return (success);
}

/*
** this would concatinate s1 with s2, and reallocate memory if
** nessecary i.e. when (S_LEN(foo) >= size - 1).
**
** s1 is allocated using cache_alloc() and free'd using cache_free()
*/

/* int		cached_read(const int fd, char **line, char **args) */
/* { */

/* } */

int		get_next_line(const int fd, char **line)
{
	static t_cache *cache[0xFF] = {NULL};
	char			*buff;
	size_t			nbytes;


	cache_alloc(&cache[fd]);
	if (cache[fd] && cache[fd]->nl)
	{
		*line = ft_strrdup(cache[fd]->buff, cache[fd]->nl);
		cache[fd]->nl = ft_strchr(cache[fd]->buff, NL);
		cache_free(&cache[fd]);
		return (success);
	}
	if (!(buff = ALLOC(char *, BUFF_SIZE + 1)) ||
			fd < 0 || !line)
		return (failure);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (cache_concat(cache[fd], buff) == failure)
			return (failure);
		printf("cache:'%s' nl:'%s'\n", cache[fd]->buff, cache[fd]->nl);

	   if ((cache[fd]->nl = ft_strchr(cache[fd]->buff, NL)))
			break ;
	   ft_bzero(buff, BUFF_SIZE);
	}
	if (IS_EOF(nbytes) && !cache[fd]->buff)
		return (eof);

	if (cache[fd]->nl)
		*line = ft_strrdup(cache[fd]->buff, cache[fd]->nl - 1);
	else
		*line = ft_strdup(cache[fd]->buff);

	printf(" >> line:'%s' cache:'%s' nl:'%s'\n",
		   *line, cache[fd]->buff, cache[fd]->nl);
	if (!*(cache[fd]->nl + 1))
		ft_strclr(cache[fd]->buff);
	cache_free(&cache[fd]);
	/* if (IS_EOF(nbytes) && cache[fd]->buff) */
	/* 	ft_strclr(cache[fd]->buff); */
	free(buff);
	printf(" >>> line:'%s' cache:'%s' nl:'%s'\n",
		   *line, cache[fd]->buff, cache[fd]->nl);
	return (success);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*s = NULL;

	if (argc != 2)
		return (0);

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &s))
	{
		i++;
		printf("%3d| '%s'\n", i, s);
		free(s);
		s = NULL;
	}
	return (0);
}
