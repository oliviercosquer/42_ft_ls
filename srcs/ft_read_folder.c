# include <ft_ls.h>

t_file	*ft_read(char *path, char *options)
{
	DIR				*stream_folder;
	t_file			*root;

	stream_folder = opendir(path);
	if (stream_folder)
	{
		root = ft_new_file(NULL);
		root->name = ft_strdup(path);
		ft_read_folder(stream_folder, options, root);
	}
	return (root);
}

void	ft_read_folder(DIR *stream, char *options, t_file *root)
{
	char			*new_path;
	struct dirent	*dirent_folder;
	t_file			*file;
	t_file			*sub_folder;
	while ((dirent_folder = readdir(stream)))
	{
		file = ft_new_file(root);
		ft_fill_file_info(file, dirent_folder);
		ft_add_file(file, root);
		if (ft_is_folder(file) && ft_strchr(options, 'R'))
		{
			if (ft_strcmp(file->name, ".") != 0
							&& ft_strcmp(file->name, "..") != 0)
			{
				new_path = ft_get_real_path(file->name, file->parent);
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
