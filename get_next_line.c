/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/22 05:21:33 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

static int extract_nl_line(char **cache, char **line)
{
    char    *nl;

    assert_ret(cache == NULL || line == NULL, failure);
    nl = *cache;
    while (*nl != NIL && *nl != NL)
        nl++;
	assert_ret(*nl == NIL, false);
	*nl = NIL;
    unless_ret(*line = ft_strdup(*cache), failure);
	unless_ret(*cache = ft_strdup(nl + 1), failure);
    return (true);
}

static int read_file(const int fd, char **cache, char **line)
{
	char		*buff;
	char		*foo;
	ssize_t		nbytes;

	unless_ret(buff = ALLOC(char *, BUFF_SIZE + 1), failure);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (*cache == NULL)
			*cache = ft_strdup(buff);
		else
		{
			foo = *cache;
			*cache = ft_strjoin(foo, buff);
			ft_strdel(&foo);
		}
		if (extract_nl_line(cache, line))
			break ;
	}
	free(buff);
	return (nbytes > 0 ? success : failure);
}

int		get_next_line(const int fd, char **line)
{
	/* static t_list	*lst = NULL; */
	static char	*cache[0xFF];
	ssize_t		nbytes;

	assert_ret(!line || fd < 0 || read(fd, NULL, 0) < 0, failure);
	assert_ret(cache[fd] && extract_nl_line(cache, line), success);
	assert_ret((nbytes = read_file(fd, &cache[fd], line)) < 0, failure);

	(void)printf("line: '%s' cache: '%s'\n", *line, cache[fd]);
	if (nbytes && !cache[fd] && !*cache[fd])
	{
		if (!nbytes && *line)
			*line = NULL;
		return (nbytes);
	}
	*line = cache[fd];
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
