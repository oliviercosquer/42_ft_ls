#include <ft_ls.h>

int     ft_is_option(char *str)
{
    if (str && str[0] == '-')
        return (1);
    return (0);
}

char	*ft_get_options(int argc, char **argv)
{
	char	*options;
	int		i;

	options = NULL;
	i = 1;
	while (i < argc && options == NULL)
	{
		if (ft_is_option(argv[i]))
			options = ft_strdup(argv[i] + 1);
		i++;
	}
	return (options);
}
