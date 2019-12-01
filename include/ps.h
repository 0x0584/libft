/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:10:29 by archid-           #+#    #+#             */
/*   Updated: 2019/11/27 10:44:34 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# define FEW_ELEMENTS							(3)

# include "libft.h"

# define GET_NODE(e)							((t_ps_node *)e->content)
# define AS_NODE(obj)							((t_ps_node *)obj)

typedef struct s_ps_array	t_ps_array;
typedef struct s_ps_node	t_ps_node;
typedef struct s_ps_ds		*t_ps;

struct						s_ps_array
{
	int		*base;
	size_t	size;
};

struct						s_ps_node
{
	int		value;
	int		a_cost;
	int		b_cost;
};

struct						s_ps_ds
{
	char	symb;
	t_lst	stack;
	size_t	len;
	size_t	size;
};

t_ps						ps_alloc(char symb, size_t size);
void						ps_del(t_ps *aps);
void						ps_dump(t_ps ps);
bool						ps_issorted(t_ps ps_a, t_ps ps_b);
t_ps_array					ps_vals_asarray(t_ps ps);
void						ps_sort_few(t_ps a, t_ps b, t_lst *ops);
bool						ps_check_node(t_ps ps, t_ps_node *node);
void						helper_node_dump(t_lst e);

int							find_range(int val, int *arr, int low, int high);
int							binary_search_min(int *arr, int low, int high);

#endif
