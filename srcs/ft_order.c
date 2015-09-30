#include <ft_ls.h>

void	ft_order(t_file **root, char *options)
{
	while (root)
	{
		ft_order_by_name_asc(root);
		ft_order_by_name_asc(&(*root)->children);
		if (ft_strchr(options, 't'))
			(void)options;
		else if (ft_strchr(options, 'r'))
		{
			ft_order_by_name_desc(root);
			ft_order_by_name_desc(&(*root)->children);
		}
		if ((*root)->left)
			root = &(*root)->left;
		else
			root = NULL;
	}
}

void	ft_swap(t_file *prev, t_file *cur, t_file *next, t_file **root)
{
		if (prev == cur)
		{
			cur->left = next->left;
			next->left = *root;
			*root = next;
		}
		else
		{
			prev->left = next;
			cur->left = next->left;
			next->left = cur;
		}
}
