

#include "push_swap.h"

int	list_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s == NULL)
		return (0);
	s->nb = content;
	s->next = NULL;
	return (s);
}

void	add_front(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new;
	}
}
