/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/14 23:10:40 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *cache[0xFF] = {NULL};
	char		*tmp[count];
	size_t		nbytes;

	/* printf(" ####  \n this is \n ###### \n"); */

	if (!(tmp[buffer] = ALLOC(char *, BUFF_SIZE + 1)))
		return (failure);
	/* printf(" ####  \n this is \n ###### \n"); */
	if (fd < 0 || !line || read(fd, tmp[buffer], 0) < 0)
		return (failure);

	if ((tmp[bar] = ft_strchr(cache[fd], 0x0A)))
	{
		*line = ft_strrdup(cache[fd], tmp[bar] - 1);
		cache[fd] = tmp[bar] + 1;
		return (success);
	}
	/* printf(" ####  \n this is \n ###### \n"); */
	while ((nbytes = read(fd, tmp[buffer], BUFF_SIZE)))
	{
		if (!(cache[fd] = ft_strjoin(!cache[fd] ? "" : cache[fd], tmp[buffer])))
		{
			puts("memory allocation failure!");
			return (failure);
		}
		printf("cache:'%s' buffer:'%s'\n", cache[fd], tmp[buffer]);
		if ((tmp[bar] = ft_strchr(tmp[buffer], 0x0A)))
		{
			puts("found a new line");
			break ;
		}
	}
	if (nbytes < BUFF_SIZE && !ft_strlen(tmp[buffer]))
	{
		puts("read returned 0. EOF");
		return (eof);
	}
	/* copy until 0x0A, excluded */
	*line = ft_strrdup(cache[fd], ft_strchr(cache[fd], 0x0A) - 1);
	if (!*(tmp[bar] + 1))
		ft_strclr(cache[fd]);
	else
		cache[fd] = tmp[bar] + 1;
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
