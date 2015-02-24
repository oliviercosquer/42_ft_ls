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
