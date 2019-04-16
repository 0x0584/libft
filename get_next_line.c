/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/16 04:53:24 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO: remove unused headers
*/
/*
** TODO: remove comments
*/
/*
** TODO: check the norm
*/
/*
**TODO: improve the code
*/
/*
** FIXEME: reorder e_fuzzbuzz
*/

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

/*
** TODO: ft_realloc()
*/

int	   cache_alloc(char **s, t_bool isfull)
{
	char *tmp[2];

	if (s == NULL)
		return (failure);
	else if (*s == NULL)
		*s = ALLOC(char *, CACHE_SIZE);
	else if (*s && isfull)
	{
		if (!(tmp[0] = ALLOC(char *, S_LEN(tmp[0]) + CACHE_SIZE)))
			return (failure);
		ft_memcpy(tmp[0], *s, S_SIZE(tmp[0]));
		tmp[1] = *s;
		free(*s);
		*s = tmp[1];
	}
	return (success);
}

void	cache_free(char **s, t_bool has_nl)
{
	char *tmp;

	if (!s || !*s)
	{
		if (has_nl)
		{
			tmp = *s;
			*s = ft_strdup(ft_strchr(*s, NL) + 1);
			free(tmp);
		}
		else
		{
			/* FIXME: something is missing here */
		}
	}
}

/*
** this would concatinate s1 with s2, and reallocate memory if
** nessecary i.e. when (S_LEN(foo) >= size - 1).
**
** s1 is allocated using cache_alloc() and free'd using cache_free()
*/

char	*cache_concat(char *s1, const char *s2, size_t size)
{

	return (s1);
}

int		get_next_line(const int fd, char **line)
{
	static char *cache[0xFF] = {NULL};
	char		*tmp[icount];
	size_t		nbytes;

	/* TODO: add a cache_alloc() somwhere in here */

	/* 0.1 check if memory is allocated */
	if (!(tmp[ibuffer] = ALLOC(char *, BUFF_SIZE + 1)))
		return (failure);
	/* 0.2 check if fd, and line and we can read the file */
	if (fd < 0 || !line || read(fd, tmp[ibuffer], 0) < 0)
		return (failure);
	/* 1.0 check if cache has already a NL */
	if (cache[fd] && (tmp[ibar] = ft_strchr(cache[fd], NL)))
	{
		/* if so duplicated from from 0 to index of NL */
		*line = ft_strrdup(cache[fd], tmp[ibar] - 1);
		// cache[fd] = tmp[ibar] + 1;
		/* free copied part of the cache using cache_free() */
		cache_free(&cache[fd], tmp[ibar] != NULL);
		return (success);
	}
	/* 2.0 if the cache does not have a NL in it, we read a BUFF_SIZE
	 * chars into our tmporary buffer */
	while ((nbytes = read(fd, tmp[ibuffer], BUFF_SIZE)))
	{
		/* 2.1 join the read chars with the previous cache content */
		if (!(cache[fd] = ft_strjoin(cache[fd] ? cache[fd] : "", tmp[ibuffer])))
			return (failure);
		/* 2.2 if we have read a NL we stop reading from fd */
		if ((tmp[ibar] = ft_strchr(tmp[ibuffer], NL)))
			break ;
	}
	/* 2.3 if we have read less than BUFF_SIZE and the temporary buffer is
	 * empty, then it must be an EOF */
	if (nbytes < BUFF_SIZE && !ft_strlen(tmp[ibuffer]))
		return (eof);
	/* 3.0 copy from cache until NL */
	*line = ft_strrdup(cache[fd], (tmp[ifoo] = ft_strchr(cache[fd], NL)) - 1);
	/* 3.1 free the copied version */
	cache_free(&cache[fd], tmp[ifoo]!= NULL);
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
