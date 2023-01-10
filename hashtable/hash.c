/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:44:57 by archid-           #+#    #+#             */
/*   Updated: 2023/01/12 23:46:40 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

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

#define SFOLD_BUFF_SIZE 32
size_t	sfold(const void *ptr, size_t mod, bool literal)
{
	size_t		size;
	char		*hash_str;

	if (literal)
	{
		size = ft_strlen(ptr);
		hash_str = (char *)ptr;
	}
	else
	{
		char buffer[SFOLD_BUFF_SIZE];
		ft_snprintf(buffer, BUFF_SIZE, "%xld", ptr);
		size = ft_strlen(buffer);
		hash_str = buffer;
	}
	return (compute_hash(
				hash_str, size / 4, compute_hash(
					hash_str, size, 0, mod),
				mod) % mod);
}

t_hashtable	hashtable_alloc(size_t size, t_del del, t_cmp cmp, bool literal)
{
	t_hashtable hash;
	size_t i;

	hash = malloc(sizeof(struct s_hashtable));
	size = ft_sqrt(size) + 1;
	hash->size = size;
	hash->array = malloc(size * sizeof(t_lst));
	hash->del = del;
	hash->cmp = cmp;
	hash->literal = literal;
	i = 0;
	while (i < size)
		hash->array[i++] = NULL;
	return (hash);
}

void	hashtable_del(t_hashtable *h)
{
	size_t		i;
	t_hashtable		hash;
	t_hashtable_node	*tmp;

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
