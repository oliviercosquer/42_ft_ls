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
	if (argc == 1 || (argc == 2 && ft_strchr(argv[1], '-') > 0))
	{
		path = ft_strdup("./");
		folder = ft_read(path, options);
		ft_strdel(&path);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strchr(argv[i], '-') == 0)
			{
				path = ft_strdup(argv[i]);
				if (folder == NULL)
					folder = ft_read(path, options);
				else
					folder->next = ft_read(path, options);
				ft_strdel(&path);
			}
			i++;
		}
	}
	ft_order(&folder, options);
	ft_display_folder(folder, options);
	return (0);
}
