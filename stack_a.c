
#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*save;

	if (*a == NULL)
		return ;
	save = (*a)->next->next;
	add_front(a, (*a)->next);
	(*a)->next->next = save;
	write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*save_a;
	t_stack	*save_b;

	if (*b == NULL)
		return ;
	save_b = (*b);
	*b = (*b)->next;
	save_a = (*a);
	add_front(a, save_b);
	(*a)->next = save_a;
	write(1, "pa\n", 3);
}

void	ft_ra(t_stack **a)
{
	t_stack	*save;

	if (!(*a))
		return ;
	save = *a;
	(*a) = (*a)->next;
	save->next = NULL;
	ft_lstadd_back(a, save);
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a)
{
	t_stack	*save;
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = (*a);
	while (temp->next->next)
		temp = temp->next;
	save = temp->next;
	temp->next = NULL;
	add_front(a, save);
	write(1, "rra\n", 4);
}
