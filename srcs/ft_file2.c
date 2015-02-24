#include <ft_ls.h>

void	ft_add_file(t_file *file, t_file *root)
{
	if (root->files)
	{
		root = root->files;
		while (root->next)
			root = root->next;
		root->next = file;
	}
	else
		root->files = file;
}

void	ft_add_folder(t_file *folder, t_file *root)
{
	while (root->next)
			root = root->next;
	root->next = folder;
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
