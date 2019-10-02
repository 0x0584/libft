#ifndef DLIST_H
# define DLIST_H

# include "libft.h"

/* NOTE: might need to change few things due to adding a
   'content type' field. in order to created a
   list of lists. */

typedef struct	s_dl_list_node
{
	struct s_dl_list_node	*next;
	struct s_dl_list_node	*prev;

	void					*blob;
	size_t					size;
	int						(*type)(void *e);
}				t_dlst_node, *t_dlst;

t_dlst_node		*ft_dlstnew(void *blob, size_t size, int (*type)(void *));
void			ft_dlstdel(void (*del)(void *, size_t), t_dlst *alst);
void			ft_dlstdelone(void (*del)(void *, size_t), t_dlst *anode);
void			ft_dlstpush(t_dlst *alst, t_dlst_node *e);
void			ft_dlstadd(t_dlst *alst, t_dlst_node *e);
t_dlst_node		*ft_dlstpop(t_dlst *alst);
t_dlst_node		*ft_dlstpeek(t_dlst *alst);


#endif /* DLIST_H */
