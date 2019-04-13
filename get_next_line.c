/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/13 16:38:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *cache = NULL;
	char		*tmp[3];

	if (!(tmp[0] = ALLOC(char *, BUFF_SIZE + 1)))
		return (RET_FAILURE);
	if (!(cache = ALLOC(char *, 1)))
		return (RET_FAILURE);
	while (read(fd, tmp[0], BUFF_SIZE))
	{
		printf("\nread: >>> '%s'\n", tmp[0]);
		if ((tmp[1] = ft_strchr(tmp[0], 0x0A)))
		{
			*line = ft_strrdup(tmp[0], tmp[1] - 1);
			tmp[2] = ft_strjoin(cache, tmp[1] - 1);
			printf("line:'%s' cache:'%s' joined:'%s'\n", *line, cache, tmp[2]);
			free(cache);
			cache = tmp[2];
			return (RET_SUCCESS);
		}
		else
		{

		}
	}
	return (RET_EOF);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*s = NULL;

	if (argc != 2)
		return (0);

	fd = open(argv[1], O_RDONLY);

	i = 0;
	while (get_next_line(fd, &s))
	{
		i++;
		printf("%d %s\n", i, s);
		free(s);
		s = NULL;
	}
	return (0);
}
