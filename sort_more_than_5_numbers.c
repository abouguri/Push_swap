

#include "push_swap.h"

void	push_chunks_to_b(int i, int *tab, t_stack **a, t_stack **b)
{
	int	key_num;
	int	size_a;
	int	pos;

	size_a = list_size(*a);
	while (i <= size_a)
	{
		key_num = tab[i];
		while (list_size(*b) <= i)
		{
			pos = search_for_pos(*a, key_num, list_size(*a));
			if (pos <= list_size(*a) / 2)
			{
				while (pos--)
					ft_ra(a);
			}
			else
			{
				while (pos++ < list_size(*a))
					ft_rra(a);
			}
			ft_pb(a, b);
		}
		i += ft_chunk(size_a);
	}
}

void	push_rest_to_b(t_stack **a, t_stack **b)
{
	int	pos;

	while (*a)
	{
		pos = search_for_small(*a);
		if (pos <= list_size(*a) / 2)
		{
			while (pos--)
				ft_ra(a);
		}
		else if (pos > list_size(*a) / 2)
		{
			while (pos++ < list_size(*a))
				ft_rra(a);
		}
		ft_pb(a, b);
	}
}

void	else_conditions(t_stack **a, t_stack **b, t_var *var)
{
	while (var->pos++ < list_size(*b))
	{
		if ((*b)->nb == var->tab[var->size_a])
		{
			ft_pa(a, b);
			var->pos--;
			var->key = 1;
		}
		ft_rrb(b);
	}
}

void	repush_conditions(t_stack **a, t_stack **b, t_var *var)
{
	if (var->pos <= list_size(*b) / 2)
	{
		while (var->pos-- > 0)
		{
			if ((*b)->nb == var->tab[var->size_a])
			{
				ft_pa(a, b);
				var->key = 1;
			}
			else
				ft_rb(b);
		}
	}
	else
		else_conditions(a, b, var);
}

void	sort_more_than_five(t_stack **a, t_stack **b)
{
	t_var	var;

	var.tab = stack_to_arr(*a);
	var.size_a = list_size(*a);
	sort_tab(var.tab, var.size_a);
	var.i = ft_chunk(var.size_a) - 1;
	push_chunks_to_b(var.i, var.tab, a, b);
	push_rest_to_b(a, b);
	var.size_a = var.size_a - 2;
	while (*b)
	{
		var.pos = search_for_big(*b);
		var.key = 0;
		repush_conditions(a, b, &var);
		ft_pa(a, b);
		if (var.key == 1)
		{
			ft_sa(a);
			var.size_a--;
		}
		var.size_a--;
	}
	free(var.tab);
}
