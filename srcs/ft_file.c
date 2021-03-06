#include <ft_ls.h>

t_file	*ft_new_file(t_file *parent)
{
	t_file	*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	new_file->left = NULL;
	new_file->name = NULL;
	new_file->children = NULL;
	new_file->root = parent;
	return (new_file);
}

void	ft_fill_file_info(t_file *file,struct dirent *dir)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		*st;

	st = (struct stat *)malloc(sizeof(struct stat));
	file->name = ft_strdup(dir->d_name);
	stat(ft_get_real_path(file->name, file->root), st);
	if (st)
	{
		pwd = getpwuid(st->st_uid);
		grp = getgrgid(st->st_gid);
		file->perms = ft_get_perms(st->st_mode);
		file->size = st->st_size;
		file->hard_links = st->st_nlink;
		file->access_time = (char *)ctime(&(st->st_ctime));
		if (pwd)
			file->owner = ft_strdup(pwd->pw_name);
		if (grp)
			file->group = ft_strdup(grp->gr_name);
	}
}

char	*ft_get_full_path(char *filename, t_file *folder)
{
	char	*tmp;
	char	*full_path;

	full_path = ft_strdup(filename);
	while (folder)
	{
		tmp = full_path;
		full_path = ft_strjoin(folder->name, full_path);
		ft_strdel(&tmp);
		folder = folder->root;
	}
	return (full_path);
}

char	*ft_get_real_path(char *filename, t_file *folder)
{
	char	*tmp;
	char	*name;
	char	*full_path;
	int		len;

	full_path = ft_strdup(filename);
	while (folder)
	{
		len = ft_strlen(folder->name);
		if (folder->name[len - 1] != '/')
		{
			name = ft_strdup("/");
			tmp = name;
			name = ft_strjoin(folder->name, name);
			ft_strdel(&tmp);
		}
		else
			name = folder->name;
		tmp = full_path;
		full_path = ft_strjoin(name, full_path);
		ft_strdel(&tmp);
		folder = folder->root;
	}
	return (full_path);
}
