/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:45:23 by archid-           #+#    #+#             */
/*   Updated: 2023/01/14 15:14:27 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>

# include "lst.h"

typedef void					(*t_del)(void *);
typedef int						(*t_cmp)(void *, void *);
typedef size_t					(*t_hashalgo)(void *key, size_t mod_size);

typedef struct s_hashtable_node	t_hashtable_node;
typedef struct s_hashtable		*t_hashtable;


struct							s_hashtable_node
{
	void			*key;
	void			*blob;
};

struct							s_hashtable
{
	t_lst			*array;
	size_t			size;
	t_del			del;
	t_cmp			cmp;
	t_hashalgo		hasher;
};

size_t							sfold_str(void *key, size_t mod_size);
size_t							hash_int(void *key, size_t mod_size);

extern t_hashalgo				g_default_algo;

t_hashtable               		hashtable_alloc(size_t size, t_del del,
												t_cmp cmp, t_hashalgo hasher);

bool	                  		hashtable_add(t_hashtable h, void *key,
											  void *blob);
void	                  		hashtable_update(t_hashtable h, void *key,
												 void *blob);
bool	                  		hashtable_remove(t_hashtable h, void *key);
void	                  		hashtable_del(t_hashtable *h);
void	                  		*hashtable_get(t_hashtable h, void *key,
											   void *val_default);
void	                  		hashtable_default_del(void *ptr);
size_t	                  		hashtable_count(t_hashtable h);
void	                  		hashtable_iter(t_hashtable h,
		                  						void (*callback)(void *key,
																 void *blob));
void	                  		hashtable_iter_arg(t_hashtable h, void *arg,
								void (*callback)(void *key, void *blob,
												 void *arg));

#endif
