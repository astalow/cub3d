#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		s += INT_MAX;
		len = ft_strlen(s);
	}
	write(fd, s, len);
}

ssize_t	ft_putstr_n(char *s, size_t	size)
{
	ssize_t	n;

	if (!s)
		return (0);
	n = 0;
	while (size > INT_MAX)
	{
		n += write(1, s, INT_MAX);
		s += INT_MAX;
		size -= INT_MAX;
	}
	n += write(1, s, size);
	return (n);
}
