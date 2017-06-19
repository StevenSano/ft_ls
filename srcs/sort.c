#include "ft_ls.h"

int				cmp_alpha(t_file *p1, t_file *p2, int reverse_cmp)
{
	int		result;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_tolower_str(ft_strdup(p1->name));
	tmp2 = ft_tolower_str(ft_strdup(p2->name));
	result = (ft_strcmp(tmp1, tmp2));
	free(tmp1);
	free(tmp2);
	if (reverse_cmp)
		return (result < 0 ? 1 : 0);
	else
		return (result > 0 ? 1 : 0);
}

int				cmp_lex(t_file *p1, t_file *p2, int reverse_cmp)
{
	if (p1->stats.st_mtimespec.tv_sec == p2->stats.st_mtimespec.tv_sec)
	{
		if (p1->stats.st_mtimespec.tv_nsec == p2->stats.st_mtimespec.tv_nsec)
			return (cmp_alpha(p1, p2, reverse_cmp));
		if (reverse_cmp)
			return (p1->stats.st_mtimespec.tv_nsec
			> p2->stats.st_mtimespec.tv_nsec);
		else
			return (p1->stats.st_mtimespec.tv_nsec
			< p2->stats.st_mtimespec.tv_nsec);
	}
	if (reverse_cmp)
		return (p1->stats.st_mtimespec.tv_sec
		> p2->stats.st_mtimespec.tv_sec);
	else
		return (p1->stats.st_mtimespec.tv_sec
		< p2->stats.st_mtimespec.tv_sec);
}

static void		lst_swap_contents(t_list *p1, t_list *p2)
{
	void		*tmp;

	tmp = p1->content;
	p1->content = p2->content;
	p2->content = tmp;
}

void ls_sort(t_list *start, int (*f)(t_file*, t_file *, int), int reverse_cmp)
{
	int     swapped;
	t_list  *left;
	t_list  *right;

	right  = NULL;
	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		left = start;
		while (left->next != right)
		{
			if (f(left->content, left->next->content, reverse_cmp))
			{
				lst_swap_contents(left, left->next);
				swapped = 1;
			}
			left = left->next;
		}
		right = left;
	}
}
