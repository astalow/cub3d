#include "libft.h"

static size_t	ft_count_digits(long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	put_num(char *rtn, int n, long long ln, size_t len)
{
	if (n == 0)
	{
		rtn[0] = '0';
		return ;
	}
	while (len > 0)
	{
		rtn[len - 1] = (char)((ln % 10) + '0');
		ln /= 10;
		len--;
	}
	if (n < 0)
		rtn[0] = '-';
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*rtn;
	long long	ln;

	ln = (long long)n;
	len = 0;
	if (ln < 0)
	{
		ln *= -1;
		len++;
	}
	len += ft_count_digits(ln);
	rtn = (char *)x_malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	put_num(rtn, n, ln, len);
	rtn[len] = '\0';
	return (rtn);
}
