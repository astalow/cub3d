#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			dgt_size;

	ln = (long long)n;
	if (ln == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	dgt_size = 1;
	while (dgt_size <= (ln / 10))
		dgt_size *= 10;
	while (dgt_size)
	{
		ft_putchar_fd(ln / dgt_size + '0', fd);
		ln %= dgt_size;
		dgt_size /= 10;
	}
}
