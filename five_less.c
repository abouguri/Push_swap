/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:55 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 22:07:56 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_less(t_stack **a)
{
	if (check_sort(*a) == 0)
		return ;
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
	if (list_size(*a) == 2)
		return ;
	if ((*a)->nb > (*a)->next->next->nb)
		rra(a);
	if ((*a)->next->nb > (*a)->next->next->nb)
	{
		sa(a);
		ra(a);
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
        	ra(a);
	}
	else
	{
    	while (i++ < list_size(*a))
        	rra(a);
	}
	pb(a, b);
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
	pa(a, b);
	pa(a, b);
	ra(a);
}
