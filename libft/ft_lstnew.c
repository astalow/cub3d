#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtn;

	rtn = (t_list *)x_malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}
