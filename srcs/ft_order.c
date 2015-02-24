#include <ft_ls.h>

void	ft_order(t_file **root, char *options)
{
	while (root)
	{
		ft_order_asc(root);
		ft_order_asc(&(*root)->files);
		if (ft_strchr(options, 't'))
			(void)options;
		else if (ft_strchr(options, 'r'))
			(void)options;
		if ((*root)->next)
			root = &(*root)->next;
		else
			root = NULL;
	}
}

void	ft_order_asc(t_file **root)
{
	int		switched;
	t_file	*prev;
	t_file	*cur;
	t_file	*next;

	switched = 1;
	while (switched)
	{
		prev = *root;
		cur = *root;
		switched = 0;
		while (cur && cur->next)
		{
			next = cur->next; 
			if (strcmp(cur->name, next->name) > 0)
			{
				ft_swap(prev, cur, next, root);
				switched = 1;
			}
			prev = cur;
			cur = next;
		}
	}
}

void	ft_swap(t_file *prev, t_file *cur, t_file *next, t_file **root)
{
		if (prev == cur)
		{
			cur->next = next->next;
			next->next = *root;
			*root = next;
		}
		else
		{
			prev->next = next;
			cur->next = next->next;
			next->next = cur;
		}
}
