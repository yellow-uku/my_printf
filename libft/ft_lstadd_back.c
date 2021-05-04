#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
	}
	else
		while (tmp)
		{
			if (tmp->next == 0)
			{
				tmp->next = new;
				new->next = NULL;
			}
			tmp = tmp->next;
		}
}
