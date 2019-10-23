#include "dlst.h"

t_dlst		ft_dlstnew(void *blob, size_t size)
{
	t_dlst lst;

	if (!(lst = ALLOC(t_dlst, 1, sizeof(t_dlst_node))))
		return (NULL);
	lst->blob = blob ? ft_memdup(blob, size) : NULL;
	lst->size = blob ? size : 0;
	return (lst);
}

void			ft_dlstdel(t_delfunc del, t_dlst *alst)
{
	t_dlst walk;
	t_dlst tmp;

	if (!SAFE_PTRVAL(alst))
		return ;
	walk = *alst;
	while (walk)
	{
		tmp = walk;
		walk = walk->next;
		ft_dlstdelone(del, &tmp);
	}
	*alst = NULL;
}

void		ft_dlstdelone(void (*del)(void *, size_t), t_dlst *anode)
{
	if (!SAFE_PTRVAL(anode))
		return ;
	if ((*anode)->prev)
		(*anode)->prev->next = (*anode)->next;
	if ((*anode)->next)
		(*anode)->next->prev = (*anode)->prev;
	(*del)((*anode)->blob, (*anode)->size);
	free(*anode);
	*anode = NULL;
}

t_dlst		ft_dlstpush(t_dlst *alst, t_dlst e)
{
	t_dlst walk;

	if (!alst || !e)
		return (NULL);
	if (!*alst)
		return (*alst = e);
	walk = *alst;
	while (walk->next)
		walk = walk->next;
	e->prev = walk;
	walk->next = e;
	return (e);
}

t_dlst		ft_dlstadd(t_dlst *alst, t_dlst e)
{
	t_dlst tmp;

	if (!alst || !e)
		return (NULL);
	else if (!*alst)
		return (*alst = e);
	tmp = *alst;
	tmp->prev = e;
	*alst = e;
	e->next = tmp;
	return (e);
}

t_dlst		ft_dlstpop(t_dlst *alst)
{
	t_dlst poped;
	t_dlst walk;

	if (!SAFE_PTRVAL(alst))
		return NULL;
	walk = *alst;
	while (walk->next)
		walk = walk->next;
	if (walk->prev)
		walk->prev->next = walk->next;
	poped = walk;
	poped->next = NULL;
	poped->prev = NULL;
	return (poped);
}

t_dlst		ft_dlstpeek(t_dlst *alst)
{
	t_dlst peeked;
	t_dlst tmp;

	if (!SAFE_PTRVAL(alst))
		return NULL;
	tmp = *alst;
	peeked = tmp;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*alst = tmp->next;
	peeked->next = NULL;
	peeked->prev = NULL;
	return (peeked);
}
