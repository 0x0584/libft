/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:34:27 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 13:37:55 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "libft.h"

typedef struct s_lst_node	*t_lstnode;
typedef struct s_lst		*t_lst;

struct		s_lst_node
{
	void		*blob;
	size_t		size;
	t_lstnode	next;
	t_lstnode	prev;
};

struct		s_lst
{
	t_lstnode	head;
	t_lstnode	tail;
	size_t		size;
	void		(*del)(void *blob);
};

t_lstnode	lst_node(void *blob, size_t size, bool alloc);
void		lst_node_free(t_lst lst, t_lstnode anode);
void		lst_node_del(t_lst lst, t_lstnode *anode);
void		lst_node_del_with(t_lstnode *anode, void (*del)(void *blob));

t_lst		lst_alloc(void (*del)(void *blob));
void		lst_free(void *lst);
void		lst_del(t_lst *alst);
void		lst_del_with(t_lst *alst, void (*del)(void *blob));

size_t		lst_size(t_lst lst);
bool		lst_empty(t_lst lst);
t_lstnode	lst_head(t_lst lst);
t_lstnode	lst_tail(t_lst lst);

t_lstnode	lst_front(t_lst lst);
t_lstnode	lst_rear(t_lst lst);

t_lst		lst_push_front(t_lst lst, t_lstnode node);
t_lst		lst_push_back(t_lst lst, t_lstnode node);
t_lstnode	lst_pop_back(t_lst lst);
t_lstnode	lst_pop_front(t_lst lst);

void		lst_iter_arg(t_lst lst, bool front, void *arg,
							void (*apply_arg)(void *blob, void *arg));
void		lst_iteri_arg(t_lst lst, bool front, void *arg,
							void (*index_apply_arg)(void *blob, size_t index,
														void *arg));

void		lst_iter(t_lst lst, bool front, void (*apply)(void *blob));
void		lst_iteri(t_lst lst, bool front,
						void (*index_apply)(void *blob, size_t index));

bool		lst_node_forward(t_lstnode *anode);
bool		lst_node_backward(t_lstnode *anode);

t_lst		lst_insert_at(t_lst lst, t_lstnode at, t_lstnode node);
t_lst		lst_insert_after(t_lst lst, t_lstnode before, t_lstnode node);
t_lst		lst_insert_before(t_lst lst, t_lstnode after, t_lstnode node);
t_lstnode	lst_extract(t_lst lst, t_lstnode node);

t_lst		lst_insertion_sort(t_lst lst, int (*cmp)(void *, void *));

void		blob_free(void *blob);
void		blob_keep(void *blob);

void		*blob_identity(void *blob);

void		*lst_front_blob(t_lst lst);
void		*lst_rear_blob(t_lst lst);

t_lst		lst_push_front_blob(t_lst lst, void *blob, size_t size, bool alloc);
t_lst		lst_push_back_blob(t_lst lst, void *blob, size_t size, bool alloc);
void		*lst_pop_back_blob(t_lst lst);
void		*lst_pop_front_blob(t_lst lst);

void		*lst_extract_blob(t_lst lst, t_lstnode *node);
t_lst		lst_clear(t_lst lst);

t_lst		lst_copy(t_lst lst, void *(*func_copy)(void *),
						void (*del)(void *));
t_lst		lst_copy_shallow(t_lst lst);
t_lst		lst_copy_deep(t_lst lst, void *(copy)(void *));

void		lst_remove(t_lst lst, t_lstnode *node);
void		lst_remove_next(t_lst lst, t_lstnode node);
void		lst_remove_previous(t_lst lst, t_lstnode node);

t_lst		lst_shrink(t_lst lst, bool from_head, size_t size);

#endif
