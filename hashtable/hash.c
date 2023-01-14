/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:44:57 by archid-           #+#    #+#             */
/*   Updated: 2023/01/14 15:14:15 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"


#define SFOLD_BUFF_SIZE 32
typedef char t_buffer[SFOLD_BUFF_SIZE];

size_t						compute_hash(t_buffer s, size_t size, size_t sum, size_t mod)
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

size_t						sfold_str(void *key, size_t mod_size)
{
	size_t						size;
	t_buffer					hash_str;

	size = ft_strlen((char *)key);
	return (compute_hash(
						hash_str, size / 4, compute_hash(
							hash_str, size, 0, mod_size),
						mod_size) % mod_size);
}

size_t						hash_int(void *data, size_t mod_size)
{
	int		x;

	x = (int)data;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return (x % mod_size);
}

t_hashtable					hashtable_alloc(size_t size, t_del del, t_cmp cmp, t_hashalgo hasher)
{
	t_hashtable		hash;
	size_t			i;

	hash = malloc(sizeof(struct s_hashtable));
	size = ft_sqrt(size) + 1;
	hash->size = size;
	hash->array = malloc(size * sizeof(t_lst));
	hash->del = del;
	hash->cmp = cmp;
	hash->hasher = hasher;
	i = 0;
	while (i < size)
		hash->array[i++] = NULL;
	return (hash);
}

void						hashtable_del(t_hashtable *h)
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

 t_hashalgo					g_default_algo = sfold_str;
