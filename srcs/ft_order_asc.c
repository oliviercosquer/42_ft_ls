#include <ft_ls.h>

void	ft_order_by_name_asc(t_file **root)
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
		while (cur && cur->left)
		{
			next = cur->left;
			if (ft_strcmp_tolower(cur->name, next->name) > 0)
			{
				ft_swap(prev, cur, next, root);
				switched = 1;
			}
			prev = cur;
			cur = next;
		}
	}
}
