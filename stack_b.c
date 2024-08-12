

#include "push_swap.h"

void	ft_sb(t_stack **b)
{
	t_stack	*save;

	if (*b == NULL)
		return ;
	save = (*b)->next->next;
	add_front(b, (*b)->next);
	(*b)->next->next = save;
	write(1, "sb\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*save_a;
	t_stack	*save_b;

	if (*a == NULL)
		return ;
	save_a = (*a);
	*a = (*a)->next;
	save_b = (*b);
	add_front(b, save_a);
	(*b)->next = save_b;
	write(1, "pb\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*save;

	if (!(*b))
		return ;
	save = *b;
	(*b) = (*b)->next;
	save->next = NULL;
	ft_lstadd_back(b, save);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*save;
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = (*b);
	while (temp->next->next)
		temp = temp->next;
	save = temp->next;
	temp->next = NULL;
	add_front(b, save);
	write(1, "rrb\n", 4);
}
