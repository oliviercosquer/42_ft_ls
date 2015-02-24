#include <ft_ls.h>

int		ft_check_errors(int argc, char **argv, char *options)
{
	int	error;
	int	i;

	error = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], '-') == 0)
			ft_check_files(argv[i]);
		i++;
	}
	error = ft_check_options(options);
	return (error);
}

int		ft_check_options(char *options)
{
	while (options && *options)
	{
		if (*options != 'a' && *options != 'l' && *options != 'r' &&
				 *options != 't' && *options != 'R')
		{
			ft_putstr("ft_ls : option non reconnue -- '");
			write(1, options, 1);
			ft_putstr("'\n");
			return (1);
		}
		options++ ;
	}
	return (0);
}

void	ft_check_files(char *path)
{

}
