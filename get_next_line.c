/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/24 20:26:07 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int		extract_nl_line(char **cache, char **line)
{
    char    *nl;

    ASSERT_RET(!cache || !*cache || !line, failure);
	(void)printf("old cache: {%s}", *cache);
	UNLESS_RET(nl = ft_strchr(*cache, NL), false);
	*nl = NIL;
    UNLESS_RET(*line = ft_strdup(*cache), failure);
	UNLESS_RET(*cache = ft_strdup(nl + 1), failure);
	(void)printf("line: [%s] new cache: {%s}\n", *line, *cache);
    return (true);
}

int		read_file(const int fd, char **cache, char **line)
{
	char		*buff;
	char		**ptr;
	ssize_t		nbytes;

	UNLESS_RET(buff = ALLOC(char *, BUFF_SIZE + 1), failure);
	/* (void)puts("###$$###$$###"); */
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		(void)printf("buff:<%s>\n", buff);
		if (*cache == NULL)
			*cache = ft_strdup(buff);
		else
		{
			ptr = cache;
			*cache = ft_strjoin(*ptr, buff);
			ft_strdel(ptr);
		}
		if (ft_strchr(*cache, NL))
			break ;
		/* (void)puts("###$$###$$###"); */
		ft_bzero(buff, BUFF_SIZE);
	}
	if (!extract_nl_line(cache, line))
	{
		*line = ft_strdup(*cache);
		ft_strdel(cache);
	}
	free(buff);
	return (nbytes > 0 ? success : failure);
}

int		get_next_line(const int fd, char **line)
{
	/* static t_list	*lst = NULL; */
	static char	*cache[0xFF] = {NULL};
	ssize_t		nbytes;

	ASSERT_RET(!line || fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0) < 0, failure);
	ASSERT_RET(cache[fd] && extract_nl_line(cache, line), success);
	ASSERT_RET((nbytes = read_file(fd, &cache[fd], line)) < 0, failure);
	/* (void)puts("###$$^^^^$$###"); */
	(void)printf("line:[%s] cache:{%s}\n", *line, cache[fd]);
	if (nbytes && !cache[fd] && !*cache[fd])
	{
		if (!nbytes && *line)
			*line = NULL;
		return (nbytes);
	}

	cache[fd] = NULL;
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
	while (get_next_line(fd, &s) == 1)
	{
		i++;
		printf("%3d| '%s'\n", i, s);
		free(s);
		s = NULL;
	}
	return (0);
}
