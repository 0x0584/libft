/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:44:57 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 12:55:31 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

size_t	compute_hash(const char *s, size_t size, size_t sum, size_t mod)
{
	size_t i;
	size_t j;
	size_t tmp;
	size_t mul;

	i = 0;
	while (i < size)
	{
		tmp = 0;
		mul = 1;
		j = i;
		while (j < i + 4 && s[j++])
		{
			tmp += s[i] * mul;
			mul *= 256;
		}
		sum = (sum + tmp) % mod;
		i++;
	}
	return (sum);
}

size_t	sfold(const char *s, size_t mod)
{
	size_t size;

	size = ft_strlen(s);
	return (compute_hash(s, size / 4,
							compute_hash(s, size, 0, mod),
						mod) % mod);
}

t_hash	hash_alloc(size_t size, void (*del)(void *))
{
	t_hash hash;
	size_t i;

	hash = malloc(sizeof(struct s_hash));
	size = ft_sqrt(size) + 1;
	hash->size = size;
	hash->array = malloc(size * sizeof(t_lst));
	hash->del = del;
	i = 0;
	while (i < size)
		hash->array[i++] = NULL;
	return (hash);
}

void	hash_del(t_hash *h)
{
	size_t		i;
	t_hash		hash;
	t_hashnode	*tmp;

	if (!h || !(hash = *h))
		return ;
	i = 0;
	while (i < hash->size)
	{
		while (!lst_empty(hash->array[i]))
		{
			tmp = lst_pop_back_blob(hash->array[i]);
			free(tmp->key);
			hash->del(tmp->blob);
			free(tmp);
		}
		lst_del(&hash->array[i++]);
	}
	free(hash->array);
	free(hash);
	*h = NULL;
}
