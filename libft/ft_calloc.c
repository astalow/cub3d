#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = x_malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return ((void *)ptr);
}
