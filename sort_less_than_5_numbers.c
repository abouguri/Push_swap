
#include "push_swap.h"

void	sort_three_less(t_stack **a)
{
	if (check_sort(*a) == 0)
		return ;
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a);
	if (list_size(*a) == 2)
		return ;
	if ((*a)->nb > (*a)->next->next->nb)
		ft_rra(a);
	if ((*a)->next->nb > (*a)->next->next->nb)
	{
		ft_sa(a);
		ft_ra(a);
	}
}

int	find_in_arr(int *arr, t_stack *a, int c)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = list_size(a);
	while (i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if ((arr[j] < arr[i]) && c == 0)
				break ;
			if ((arr[j] > arr[i]) && c == 1)
				break ;
			j++;
		}
		if (j == l)
			break ;
		i++;
	}
	free (arr);
	return (i);
}

int	*stack_to_arr(t_stack *a)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * list_size(a));
	if (!tab)
		exit (0);
	while (a)
	{
		tab[i] = a->nb;
		a = a->next;
		i++;
	}
	return (tab);
}

void	push_to_b(t_stack **a, t_stack **b, int i)
{
	if (i < 3)
	{
    	while (i-- > 0)
        	ft_ra(a);
	}
	else
	{
    	while (i++ < list_size(*a))
        	ft_rra(a);
	}
	ft_pb(a, b);
}

void	sort_five_less(t_stack **a, t_stack **b)
{
	int	*arr;
	int	i;

	if (check_sort(*a) == 0)
		return ;
	arr = stack_to_arr(*a);
	i = find_in_arr(arr, *a, 1);
	push_to_b(a, b, i);
	arr = stack_to_arr(*a);
	i = find_in_arr(arr, *a, 0);
	push_to_b(a, b, i);
	sort_three_less(a);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_ra(a);
}
