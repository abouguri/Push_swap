/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:54:18 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 21:54:19 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*save;

	if (*a == NULL)
		return ;
	save = (*a)->next->next;
	add_front(a, (*a)->next);
	(*a)->next->next = save;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
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

void	ra(t_stack **a)
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

void	rra(t_stack **a)
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
