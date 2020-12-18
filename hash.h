/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:45:23 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 12:57:08 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>

# include "lst.h"

typedef struct s_hash_node	t_hashnode;
typedef struct s_hash		*t_hash;

struct			s_hash_node
{
	char			*key;
	void			*blob;
};

struct			s_hash
{
	t_lst			*array;
	size_t			size;
	void			(*del)(void *);
};

t_hash			hash_alloc(size_t size, void (*del)(void *));

bool			hash_add(t_hash h, const char *key, void *blob);
void			hash_del(t_hash *h);
void			*hash_get(t_hash h, const char *key, void *val_default);
void			hash_default_del(void *ptr);
size_t			hash_count(t_hash h);
void			hash_iter(t_hash h,
							void (*callback)(const char *key, void *blob));

size_t			sfold(const char *s, size_t mod);

#endif
