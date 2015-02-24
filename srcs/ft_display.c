#include <ft_ls.h>

char	*ft_get_options(int argc, char **argv)
{
	char	*options;
	int		i;

	options = NULL;
	i = 1;
	while (i < argc && options == NULL)
	{
		if (ft_strchr(argv[i], '-'))
			options = ft_strdup(argv[i] + 1);
		i++;
	}
	return (options);
}

void	ft_display_folder(t_file *root, char *options)
{
	int		many;
	char	*name;

	many = 0;
	while (root)
	{
		name = ft_strchr(root->name, '/') + 1;
		if (root->next)
			many = 1;
		if ((ft_strchr(options, 'l') && many) || ft_strchr(options, 'R'))
		{
			if (name[0] != '.' || ft_strchr(options, 'a'))
			{
				ft_putstr(root->name);
				ft_putstr(":\n");
				ft_display_files(root->files, options);
				ft_putstr("\n");
			}
		}
		else
			ft_display_files(root->files, options);
		root = root->next;
	}
}

void	ft_display_files(t_file *files, char *options)
{
	while (files)
	{
		if (ft_strchr(options, 'l'))
			ft_display_lfiles(files, options);
		else if (ft_strchr(options, 'a') || files->name[0] != '.')
		{
			ft_putstr(files->name);
			ft_putstr("  ");
		}
		files = files->next;
	}

	if (ft_strchr(options, 'l') == 0)
		ft_putstr("\n");
}

void	ft_display_lfiles(t_file *files, char *options)
{
	if (ft_strchr(options, 'l'))
	{
		if (ft_strchr(options, 'a') || files->name[0] != '.')
		{
			ft_putstr(files->perms);
			ft_putstr(" ");
			ft_putnlink_t(files->hard_links);
			ft_putstr(" ");
			ft_putstr(files->owner);
			ft_putstr(" ");
			ft_putstr(files->group);
			ft_putstr(" ");
			ft_putoff_t(files->size);
			ft_putstr(" ");
			ft_putstr(files->name);
			ft_putstr("\n");
		}
	}
}
