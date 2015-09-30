# include <ft_ls.h>

void	ft_putoff_t(off_t size)
{
	char	nbr;

	nbr = '0' + size;
	if (size >= 10)
	{
		ft_putoff_t(size / 10);
		ft_putoff_t(size % 10);
	}
	else
		write(1, &nbr, 1);
}

void	ft_putnlink_t(nlink_t size)
{
	char	nbr;

	nbr = '0' + size;
	if (size >= 10)
	{
		ft_putoff_t(size / 10);
		ft_putoff_t(size % 10);
	}
	else
		write(1, &nbr, 1);
}

int		ft_strcmp_tolower(char *s1, char *s2)
{
	int		cmp;
	char	*str1;
	char	*str2;
	char	*tmp;

	str1 = ft_strdup(s1);
	str2 = ft_strdup(s2);
	tmp = str1;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	tmp = str2;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	cmp = strcmp(str1, str2);
	if (str1)
		ft_strdel(&str1);
	if (str2)
		ft_strdel(&str2);
	return (cmp);
}
