# include <ft_ls.h>

t_file	*ft_read(char *path, char *options)
{
	DIR				*stream_folder;
	t_file			*root;

	stream_folder = NULL;
	stream_folder = opendir(path);
	root = NULL;

	if (stream_folder)
	{
		root = ft_new_file(NULL);
		root->name = ft_strdup(path);
		ft_read_folder(stream_folder, options, root);
		ft_order(&root, options);
		ft_display_folder(root, options);
	}
	else
	{
		ft_putstr(path);
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	closedir(stream_folder);
	return (root);
}

void	ft_read_folder(DIR *stream, char *options, t_file *root)
{
	char			*new_path;
	struct dirent	*dirent_folder;
	t_file			*file;
	t_file			*sub_folder;

	new_path = NULL;
	dirent_folder = NULL;
	file = NULL;
	sub_folder = NULL;
	while ((dirent_folder = readdir(stream)))
	{
		file = ft_new_file(root);
		ft_fill_file_info(file, dirent_folder);
		ft_add_file(file, root);
		if (file && ft_is_folder(file) && ft_strchr(options, 'R'))
		{
			//ft_putstr("SEG\n");
			if (ft_strcmp(file->name, ".") != 0
							&& ft_strcmp(file->name, "..") != 0)
			{
				//ft_putstr("SEG\n");
				new_path = ft_get_real_path(file->name, file->parent);
				//printf("path: %s\n", new_path);
				sub_folder = ft_read(new_path, options);
				ft_add_folder(sub_folder, root);
			}
		}
	}
}

int		ft_is_folder(t_file *file)
{
	int			is_folder;
	struct stat	*file_stat;
	char		*path;

	file_stat = (struct stat *)malloc(sizeof(struct stat));
	path = ft_get_real_path(file->name, file->parent);
	is_folder = 0;
	stat(path, file_stat);
	if (S_ISDIR(file_stat->st_mode))
		is_folder = 1;
	free(file_stat);
	return (is_folder);
}
