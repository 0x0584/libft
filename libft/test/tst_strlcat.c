/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 04:49:36 by archid-           #+#    #+#             */
/*   Updated: 2019/05/03 04:49:39 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "testing.h"

int main(int argc, char *argv[]) {
	size_t sz = 1;
	int i = 2;
	char *str;

	if (argc <= 3)
		return 0;
	sz += strlen(argv[1]);
	printf("'%s", argv[1]);
	while (i < argc - 1) {
		sz += strlen(argv[i]);
		printf(" %s", argv[i]);
		i++;
	}
	printf("' ");
	str = ft_memalloc(sz * sizeof(char));
	i = 1;
	while (i < argc - 1) {
		//	str = ft_strlcat(str, argv[i], atoi(argv[argc - 1]));
		i++;
	}
	printf("'%s'\n", str);
	free(str);
	return 0;
}
