#include <ft_ls.h>

t_file	*ft_create_root(int argc, char **argv)
{
	t_file	*root_files;
	t_file	*tmp;
	int		i;

	root_files	= NULL;
	tmp	= NULL;
	i = 1;

	while (i < argc)
	{
		if (!ft_is_option(argv[i]))
		{
			tmp = ft_new_file(NULL);
			tmp->name = ft_strdup(argv[i]);
			if (!root_files)
				root_files = tmp;
			else
				ft_add_folder(tmp, root_files);
		}
		i++;
	}
	return (root_files);
}

void	ft_add_file(t_file *file, t_file *root)
{
	if (root->children)
	{
		root = root->children;
		while (root->left)
			root = root->left;
		root->left = file;
	}
	else
		root->children = file;
}

void	ft_add_folder(t_file *folder, t_file *root)
{
	while (root->left)
			root = root->left;
	root->left = folder;
}

char	*ft_get_perms(mode_t bin_perms)
{
	char	*perms;

	perms = ft_strdup("----------");
	if (S_ISDIR(bin_perms))
			perms[0] = 'd';
	if (bin_perms & S_IRUSR)
			perms[1] = 'r';
	if (bin_perms & S_IWUSR)
			perms[2] = 'w';
	if (bin_perms & S_IXUSR)
			perms[3] = 'x';
	if (bin_perms & S_IRGRP)
			perms[4] = 'r';
	if (bin_perms & S_IWGRP)
			perms[5] = 'w';
	if (bin_perms & S_IXGRP)
			perms[6] = 'x';
	if (bin_perms & S_IROTH)
			perms[7] = 'r';
	if (bin_perms & S_IWOTH)
			perms[8] = 'w';
	if (bin_perms & S_IXOTH)
			perms[9] = 'x';
	return (perms);
}
