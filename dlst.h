#ifndef DLIST_H
# define DLIST_H

# include "libft.h"

/* NOTE: might need to change few things due to adding a
   'content type' field. in order to created a list of lists. */

typedef void				(*t_delfunc)(void *, size_t);

typedef struct	s_dlst_node
{
	void				*blob;
	size_t				size;

    struct s_dlst_node	*next;
    struct s_dlst_node	*prev;
}				t_dlst_node, *t_dlst;

t_dlst			ft_dlstnew(void *blob, size_t size);
void			ft_dlstdel(t_delfunc del, t_dlst *alst);
void			ft_dlstdelone(t_delfunc del, t_dlst *anode);

t_dlst			ft_dlstpush(t_dlst *alst, t_dlst e);
t_dlst			ft_dlstpop(t_dlst *alst);
t_dlst			ft_dlstadd(t_dlst *alst, t_dlst e);
t_dlst			ft_dlstpeek(t_dlst *alst);

#endif
