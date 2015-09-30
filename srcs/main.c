#include <libft.h>
#include <ft_ls.h>

int		main(int argc, char **argv)
{
	char	*path;
	char	*options;
	t_file	*folder;
	int		i;

	folder = NULL;
	options = ft_get_options(argc, argv);
	if (ft_check_errors(argc, argv, options))
		return (0);
	if (argc == 1 || (argc == 2 && ft_strlen(options) > 0))
	{
		path = ft_strdup("./");
		folder = ft_read(path, options);
		ft_strdel(&path);
	}
	else
	{
		folder = ft_create_root(argc, argv);
		ft_order(&folder, options);
		while (folder)
		{
			ft_read(folder->name, options);
			folder = folder->left;
		}
	}
	return (0);
}
