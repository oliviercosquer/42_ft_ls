#include <ft_ls.h>

void	ft_display_folder(t_file *root, char *options)
{
	int		many;
	char	*name;

	many = 0;
	(void)root;

	name = ft_strchr(root->name, '/') + 1;
	if (root->left)
		many = 1;
	if ((ft_strchr(options, 'l') && many) || ft_strchr(options, 'R'))
	{
		if (name[0] != '.' || ft_strchr(options, 'a'))
		{
			ft_putstr(root->name);
			ft_putstr(":\n");
			ft_display_files(root->children, options);
			ft_putstr("\n");
		}
	}
	else
		ft_display_files(root->children, options);
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
		files = files->left;
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
			ft_putstr("\t");
			ft_putoff_t(files->size);
			ft_putstr("\t");
			ft_display_time(files->access_time);
			ft_putstr("\e[34m");
			ft_putstr(files->name);
			ft_putstr("\e[39m");
			ft_putstr("\n");
		}
	}
}

void ft_display_time(char *time)
{
	char	**info;

	info = ft_strsplit(time, ' ');
	if (info)
	{
		ft_putstr(info[1]);
		ft_putstr(" ");
		ft_putstr(info[2]);
		ft_putstr(" ");
		write(1, info[3], ft_strlen(info[3]) - 3);
		ft_putstr(" ");
	}
}
