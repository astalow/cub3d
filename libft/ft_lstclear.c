#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del || !(*lst))
		return ;
	while (tmp)
	{
		nxt = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = nxt;
	}
	*lst = NULL;
}
