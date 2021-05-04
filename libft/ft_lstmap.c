#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	lst_new = 0;
	while (lst)
	{
		if (!(tmp = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, tmp);
		lst = lst->next;
	}
	return (lst_new);
}
