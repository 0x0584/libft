/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/04/30 20:43:29 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int		extract_nl_line(char **cache, char **line)
{
    char    *nl;
	char	*old_cache;			/* FIXME: old cache must be free'd
								 *
								 * there is a leak here!
								 */
	/* printf("in extract_nl_line('%s', '%s')\n---------------\n", */
	/* 	   *cache, *line); */

    ASSERT_RET(!cache || !*cache || !line, failure);
	/* (void)printf("enl@old cache: {%s}\n", *cache); */
	old_cache = *cache;
	UNLESS_RET(nl = ft_strchr(*cache, NL), false);
	*nl = NIL;
    UNLESS_RET(*line = ft_strdup(*cache), failure);
	UNLESS_RET(*cache = ft_strdup(nl + 1), failure);
	/* (void)printf("\n \n >>> final output: line: [%s] enl@new cache: {%s}\n\n", */
	/* 			 *line, *cache); */
	/* FIXME: free the old *cache */
	free(old_cache);
	return (true);
}

ssize_t		cached_read(const int fd, char **cache, char **line)
{
	char		*buff;
	char		*old_cache;
	ssize_t		nbytes;

	char		*tmp = NULL;

	/* printf("in read_file(%d, '%s', '%s')\n---------------\n", */
	/* 	   fd, *cache, *line); */
	UNLESS_RET(buff = ALLOC(char *, BUFF_SIZE + 1), failure);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		/* (void)printf("\n$> read buff:<%s>\n\n", buff); */
		if (*cache == NULL) {
			*cache = ft_strdup(buff);
			/* (void)printf("cache was NULL, new value is [%s]\n", buff); */
		}
		else
		{
			old_cache = *cache; /* saving a pointer to free it later */
			*cache = ft_strjoin(old_cache, buff); /* replace the cache */
			/* (void)printf("old cache:[%s] new cache:[%s]\n", old_cache, *cache); */
			free(old_cache); /* FIXME: use few reallocations for cache
							  *
							  * this is not a wise way to handle
							  * memory this must be done otherwise
							  * but effecianlty! */
		}

		if ((tmp = ft_strchr(*cache, NL))) {
			/* (void)printf("\nnew line found, rest is {%s}\n\n", tmp); */
			break ;
		}
		/* (void)printf("\n >>> [%zu]\n", nbytes); */
	}
	ft_strdel(&buff);
	/* (void)printf("cache :: [%s]\n", *cache); */
	/* printf("read bytes => %zu", nbytes); */

	if (nbytes == 0 && *cache)
	{
		*line = ft_strdup(*cache);
		ft_strdel(cache);
		return (eof);
	}
	/* (void)printf("!!! stop reading! final cache:[%s] !!!\n\n", *cache); */
	if (!extract_nl_line(cache, line))
	{
		*line = ft_strdup(*cache);
		/* (void)printf("%s cache has no newline\n" */
		/* 			 "free it and set it to NULL", *line); */
	}

	/* (void)printf("freeing the buffer <%s>\n" */
	/* 			 "ret value %zu\n", buff, nbytes); */
	return (nbytes);
}

int		get_next_line(const int fd, char **line)
{
	/* static t_list	*lst = NULL; */
	static char	*cache[0xFF] = {NULL};
	int			nbytes;

	ASSERT_RET(BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0, failure);
	ASSERT_RET(!line || fd < 0, failure);

	/* (void)printf("%s %d\n", "BUFF_SIZE:", BUFF_SIZE); */
	/* (void)printf("%s", "everything is safe\n\n"); */
	/* printf("==> previous cache[%d] = '%s'\n", fd, cache[fd]); */

	*line = NULL;
	/* ASSERT_RET(cache[fd] && extract_nl_line(cache, line), success); */
	if (cache[fd]) {

		/* (void)printf("  -*-  %s [%s] -*- \n \t -------------------- \n", */
		/* 			 "gnl@cache found! old:", cache[fd]); */
		if (extract_nl_line(&cache[fd], line)) {
			/* (void)printf("%s [%s]\n", "new: ", cache[fd]); */
			return (success);
		}
	}
	ASSERT_RET((nbytes = cached_read(fd, &cache[fd], line)) < 0, failure);

	/* (void)printf("\n >>> read was done! \n     line@gnl:[%s] cache@gnl:{%s}\n\n", */
	/* 			 *line, cache[fd]); */

	/* TODO:  ==================== HERE IS THE BUG! ====================  */


	if (nbytes == 0)
	{
		if (*line && ft_strlen(*line) != 0)
			return (success);
		return (eof);
	}



	/* (void)printf("%s [%s] ", "final gnl@cache", cache[fd]); */
	/* (void)printf("%s [%s] ", "final gnl@line", *line); */
	/* (void)printf("'%s' '%s'", cache[fd], *line); */
	return (success);
}

/* int				main(void) */
/* { */
/* 	char		*line; */
/* 	int			fd; */
/* 	int			ret; */
/* 	int			count_lines; */
/* 	char		*filename; */
/* 	int			errors; */

/* 	filename = "gnl7_1.txt"; */
/* 	fd = open(filename, O_RDONLY); */
/* 	if (fd > 2) */
/* 	{ */
/* 		count_lines = 0; */
/* 		errors = 0; */
/* 		line = NULL; */
/* 		while ((ret = get_next_line(fd, &line)) > 0) */
/* 		{ */
/* 			if (count_lines == 0 && strcmp(line, "12345678") != 0) */
/* 				errors++; */
/* 			count_lines++; */
/* 			(void)printf(">>> count: %d line: %s\n", count_lines, line); */
/* 			if (count_lines > 50) */
/* 				break ; */
/* 		} */
/* 		close(fd); */
/* 		if (count_lines != 1) */
/* 			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines); */
/* 		if (errors > 0) */
/* 			printf("-> must have read \"12345678\" instead of \"%s\"\n", line); */
/* 		if (count_lines == 1 && errors == 0) */
/* 			printf("OK\n"); */
/* 	} */
/* 	else */
/* 		printf("An error occured while opening file %s\n", filename); */
/* 	return (0); */
/* } */

/* int		main(int argc, char **argv) */
/* { */
/* 	int		fd, i = 0; */
/* 	size_t	nbytes; */
/* 	char	*str = NULL; */

/* 	if (argc != 2) */
/* 		return (0); */

/* 	fd = open(argv[1], O_RDONLY); */
/* 	while ((nbytes = get_next_line(fd, &str)) == 1) */
/* 	{ */
/* 		i++; */
/* 		printf("\n\n   ===> %3d| '%s'\n\n", i, str); */
/* 		printf("freeing the line, gnl@ret: %zu\n\n", nbytes); */
/* 		ft_strdel(&str); */
/* 	} */
/* 	printf("final gnl@ret: %zu\n final gnl@line: '%s'\n", nbytes, str); */
/* 	ft_strdel(&str); */
/* 	return (0); */
/* } */
