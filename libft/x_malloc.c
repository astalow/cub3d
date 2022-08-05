#include "libft.h"

void	*x_malloc(size_t size)
{
	void	*content;

	content = malloc(size);
	if (content == NULL)
		exit_error(MALLOC_ERROR);
	return (content);
}
