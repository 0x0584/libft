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

void		ft_dlstdel(t_delfunc del, t_dlst *alst)
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
		return (*alst = ft_dlstnulify(e));
	walk = *alst;
	while (walk->next)
		walk = walk->next;
	ft_dlstset(walk, e, walk->next);
	walk->next = e;
	return (e);
}

t_dlst		ft_dlstadd(t_dlst *alst, t_dlst e)
{
	t_dlst tmp;

	if (!alst || !e)
		return (NULL);
	else if (!*alst)
		return (*alst = ft_dlstnulify(e));
	ft_dlstnulify(e);
	tmp = *alst;
	ft_dlstset(tmp->prev, e, tmp);
	if (tmp->prev)
		tmp->prev->next = e;
	tmp->prev = e;
	*alst = e;
	return (e);
}

t_dlst		ft_dlstpop(t_dlst *alst)
{
	t_dlst poped;
	t_dlst walk;

	if (!SAFE_PTRVAL(alst))
		return (NULL);
	walk = *alst;
	while (walk->next)
		walk = walk->next;
	if (walk->prev)
		walk->prev->next = walk->next;
	poped = walk;
	return (ft_dlstnulify(poped));
}

t_dlst		ft_dlstpeek(t_dlst *alst)
{
	t_dlst peeked;
	t_dlst tmp;

	if (!SAFE_PTRVAL(alst))
		return (NULL);
	tmp = *alst;
	peeked = tmp;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*alst = tmp->next;
	return (ft_dlstnulify(peeked));
}

t_dlst		ft_dlstset(t_dlst prev, t_dlst node, t_dlst next)
{
	if (!node)
		return (NULL);
	node->prev = prev;
	node->next = next;
	return (node);
}

t_dlst		ft_dlstnulify(t_dlst node)
{
	if (!node)
		return NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlst		ft_dlst_gettail(t_dlst head)
{
	t_dlst tail;

	if (!head)
		return (NULL);
	tail = head;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

void		ft_dlstiter(t_dlst lst, void (*callback)(t_dlst))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*callback)(lst);
		lst = lst->next;
	}
}


static t_dlst		helper_merge(t_dlst left, t_dlst right,
								 int (cmp)(t_dlst, t_dlst))
{
	t_dlst root;
	bool	sort_on_left;

	if (!left || !right)
		return (!left ? right : left);
	sort_on_left = cmp(left, right) > 0;
	root = sort_on_left ? left : right;
	root->next = helper_merge(sort_on_left ? left->next : left,
							  sort_on_left ? right : right->next,
							  cmp);
	return (root);
}

static void			helper_halfsplit(t_dlst root, t_dlst *ahead,
										t_dlst *atail)
{
	t_dlst foo;
	t_dlst bar;

	bar = root;
	foo = root->next;
	while (foo)
	{
		foo = foo->next;
		if (foo)
		{
			bar = bar->next;
			foo = foo->next;
		}
	}
	*ahead = root;
	*atail = bar->next;
	bar->next = NULL;
}

static void		helper_fix_prev(t_dlst lst)
{
	t_dlst prev;

	if (lst == NULL)
		return ;
	lst->prev = NULL;
	prev = NULL;
	while (lst)
	{
		lst->prev = prev;
		prev = lst;
		lst = lst->next;
	}
}

void				ft_dlstmergesort(t_dlst *alst, int (cmp)(t_dlst, t_dlst))
{
	t_dlst left;
	t_dlst right;

	if (!alst || !*alst || !(*alst)->next)
		return ;
	helper_halfsplit(*alst, &left, &right);
	ft_dlstmergesort(&left, cmp);
	ft_dlstmergesort(&right, cmp);
	helper_fix_prev(*alst = helper_merge(left, right, cmp));
}
