/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/14 15:09:18 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *cache[0xFF] = {NULL};
	char		*tmp[3];
	size_t		nbytes;

	if (!(tmp[0] = ALLOC(char *, BUFF_SIZE + 1)))
		return (RET_FAILURE);
	if (fd < 0 || line == NULL || read(fd, tmp[0], 0) < 0)
		return (RET_FAILURE);
	if (cache[fd] != NULL)
	{
		if ((tmp[2] = ft_strchr(cache[fd], '\n')))
		{
			*line = ft_strrdup(cache[fd], tmp[2] - 1);
			tmp[1] = ft_strdup(tmp[2] + 1);
			ft_strdel(&cache[fd]);
			cache[fd] = tmp[1];
		}
		else
		{

		}
		printf("\n line:'%s' cache[fd]'%s' \n", *line, cache[fd]);
		return (RET_SUCCESS);
	}
	else
	{
		if (!(cache[fd] = ALLOC(char *, 1)))
			return (RET_FAILURE);
	}
	while ((nbytes = read(fd, tmp[0], BUFF_SIZE)))
	{
		if ((tmp[2] = ft_strchr(tmp[0], 0x0A)))
		{
			if (cache[fd])
				*line = ft_strjoin(cache[fd], ft_strrdup(tmp[0], tmp[2] - 1));
			else
				*line = ft_strdup(tmp[0]);
			ft_strdel(&cache[fd]);
			cache[fd] = ft_strdup(tmp[2] + 1);
			printf("\n----saved: '%s'----\n", cache[fd]);
			free(tmp[0]);
			return (RET_SUCCESS);
		}
		else
		{
			tmp[1] = ft_strjoin(cache[fd], tmp[0]);
			free(cache[fd]);
			cache[fd] = tmp[1];
		}
	}
	puts("read returned 0");
	free(tmp[0]);
	return (RET_EOF);
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
